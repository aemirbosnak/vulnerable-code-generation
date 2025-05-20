#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg) {
  pthread_t thread_id = (pthread_t)arg;
  sleep(rand() % 5);
  int *ptr = NULL;
  *ptr = 10;
  printf("Thread ID: %ld, Value: %d\n", thread_id, *ptr);
  return NULL;
}

int main() {
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
