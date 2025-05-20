#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
void *thread_func(void *arg) {
  int *ptr = (int *)arg;
  printf("Thread %d: Attempting to dereference null pointer...\n", *ptr);
  int value = *ptr;
  printf("Thread %d: Dereference failure! Value is: %d\n", *ptr, value);
  pthread_exit(NULL);
}

int main() {
  int i;
  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }
  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
