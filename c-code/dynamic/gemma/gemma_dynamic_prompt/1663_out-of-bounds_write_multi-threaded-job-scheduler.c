#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[10];
int data[10] = {0};

void* thread_func(void* ptr) {
  int idx = (int)ptr;
  data[idx] = 10;
  pthread_exit(NULL);
}

int main() {
  pthread_create(threads, NULL, thread_func, (void*)0);
  pthread_create(threads + 1, NULL, thread_func, (void*)1);
  pthread_create(threads + 2, NULL, thread_func, (void*)2);
  pthread_create(threads + 3, NULL, thread_func, (void*)3);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
  pthread_join(threads[3], NULL);
  return 0;
}
