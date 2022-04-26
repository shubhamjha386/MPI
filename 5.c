#include "pthread.h"
#include <stdio.h>
#include <stdlib.h>
int sum; /* this data is shared by the thread(s) */
void *runner(void *param); /* the thread */
int main(int argc, char *argv[]) {
int count, i;
pthread_attr_t attr;
if (argc != 2) {
fprintf(stderr, "usage: pthreads <integer value>\n");
return -1;
}
count = atoi(argv[1]);
if (count < 1) {
fprintf(stderr, "%d must be>= 1\n", count);
return -1;
}
pthread_attr_init(&attr);
for (i = 0; i <= count; i++) {
pthread_t thread;
pthread_create(&thread, &attr, runner, &i);
pthread_join(thread, NULL);
printf("fib of %d is %d\n", i, sum);
}
}
int fibonacci(int x) {
if (x == 0 || x == 1)
return x;
return fibonacci(x - 1) + fibonacci(x - 2);
}
void *runner(void *param) {
int y = *((int *)param);
sum = fibonacci(y);
pthread_exit(0);
}