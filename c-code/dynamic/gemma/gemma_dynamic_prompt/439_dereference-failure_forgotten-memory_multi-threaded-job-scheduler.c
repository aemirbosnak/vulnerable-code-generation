#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[100];
int *thread_data[100];

void *thread_func(void *arg) {
  int i = (int *)arg;
  thread_data[i] = malloc(10);
  sleep(rand() % 5);
  free(thread_data[i]);
  pthread_exit(NULL);
}

int main() {
  int i;
  for (i = 0; i < 100; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }
  for (i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
