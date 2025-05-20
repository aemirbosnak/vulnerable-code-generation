#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

pthread_t threads[NUM_THREADS];
int arr[NUM_THREADS];

void *thread_function(void *thread_id) {
  int tid = (int)thread_id;
  arr[tid] = 10;
  return NULL;
}

int main() {
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void *)i);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
