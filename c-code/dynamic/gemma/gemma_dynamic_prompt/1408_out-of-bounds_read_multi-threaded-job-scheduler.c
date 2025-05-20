#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[10];
int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void* thread_func(void* arg) {
  int idx = (int)arg;
  sleep(rand() % 5);
  data[idx] = 10;
  return NULL;
}

int main() {
  pthread_create(threads, NULL, thread_func, (void*)0);
  pthread_create(threads, NULL, thread_func, (void*)1);
  pthread_create(threads, NULL, thread_func, (void*)2);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);

  return 0;
}
