#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg) {
  int *ptr = (int *)arg;
  printf("Thread %d: Attempting to dereference pointer: %p\n", *ptr, ptr);
  *ptr = NULL; // Deliberate dereference failure
  printf("Thread %d: Pointer dereference failed!\n", *ptr);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[5];
  int i;
  int *arr = NULL;

  // Allocate memory for the array (not enough for the threads)
  arr = (int *)malloc(sizeof(int) * 3);

  // Create and start threads
  for (i = 0; i < 5; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)arr);
  }

  // Join threads
  for (i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
