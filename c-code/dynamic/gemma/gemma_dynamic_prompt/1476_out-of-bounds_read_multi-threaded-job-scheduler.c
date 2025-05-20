#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
  int *buffer = (int *)arg;
  read(*buffer, NULL, 0);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[10];
  int buffers[10];

  for (int i = 0; i < 10; i++) {
    buffers[i] = i;
    pthread_create(&threads[i], NULL, thread_func, (void *)buffers[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
