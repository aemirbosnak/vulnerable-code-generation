#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
  int *ptr = (int *)arg;
  sleep(1);
  printf("Thread %d: Trying to dereference null pointer: %p\n", *ptr, ptr);
  *ptr = NULL;
  return NULL;
}

int main() {
  pthread_t threads[10];
  int i;
  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }
  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
