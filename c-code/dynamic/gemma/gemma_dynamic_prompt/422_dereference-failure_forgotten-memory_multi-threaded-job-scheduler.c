#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[10];
int *ptrs[10];

void *thread_func(void *arg) {
  int i = (int)arg;
  ptrs[i] = malloc(10);
  *ptrs[i] = 42;
  sleep(1);
  free(ptrs[i]);
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
