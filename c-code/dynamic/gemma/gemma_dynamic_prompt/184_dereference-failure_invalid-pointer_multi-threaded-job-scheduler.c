#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>

void *thread_func(void *ptr) {
  int *num = (int *)ptr;
  int result = *(num + 1);
  printf("Thread %d: result = %d\n", *num, result);
  return NULL;
}

int main() {
  pthread_t threads[10];
  int i, *arr = NULL;

  // Allocate memory for 10 threads and an array
  arr = (int *)malloc(sizeof(int) * 10);
  if (arr == NULL) {
    return 1;
  }

  // Create and start 10 threads
  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, &arr[i]);
  }

  // Join all threads
  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  // Free memory
  free(arr);

  return 0;
}
