#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t threads[10];
int data[10] = { 0 };

void* thread_func(void* arg) {
  int idx = (int)arg;
  data[idx] = 10;
  return NULL;
}

int main() {
  pthread_create(threads, NULL, thread_func, (void*)0);
  pthread_join(threads[0], NULL);
  return 0;
}
