#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

void *thread_func(void *arg) {
  int *ptr = (int *)arg;
  printf("Thread %d: Trying to access memory at address %p\n", *ptr, ptr);
  // Null pointer dereference
  int value = *(ptr + 1);
  printf("Thread %d: Value at address %p is %d\n", *ptr, ptr, value);
  return NULL;
}

int main() {
  pthread_t thread_id[2];
  int thread_args[2] = {1, 2};

  pthread_create(&thread_id[0], NULL, thread_func, (void *)thread_args[0]);
  pthread_create(&thread_id[1], NULL, thread_func, (void *)thread_args[1]);

  pthread_join(thread_id[0], NULL);
  pthread_join(thread_id[1], NULL);

  return 0;
}
