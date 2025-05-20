#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
int shared_arr[10] = {0};

void* thread_routine(void* ptr) {
  int i = (int)ptr;
  shared_arr[i] = 10;
  return NULL;
}

int main() {
  pthread_create(threads, NULL, thread_routine, (void*)0);
  pthread_create(threads + 1, NULL, thread_routine, (void*)1);
  pthread_create(threads + 2, NULL, thread_routine, (void*)2);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);

  return 0;
}
