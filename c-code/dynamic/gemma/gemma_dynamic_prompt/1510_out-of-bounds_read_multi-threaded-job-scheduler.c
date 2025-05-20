#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[10];
int shared_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void* thread_func(void* arg) {
  int idx = (int)arg;
  shared_arr[idx] = 100;
  return NULL;
}

int main() {
  pthread_create(threads, NULL, thread_func, (void*)0);
  pthread_create(threads + 1, NULL, thread_func, (void*)1);
  pthread_create(threads + 2, NULL, thread_func, (void*)2);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);

  return 0;
}
