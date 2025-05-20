#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg) {
  int *arr = (int *)arg;
  int index = rand() % 10;
  printf("Thread %ld reads value at index %d: %d\n", (long)pthread_self(), index, arr[index]);
  return NULL;
}

int main() {
  pthread_t threads[10];
  int arr[10] = {0};
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)arr);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
