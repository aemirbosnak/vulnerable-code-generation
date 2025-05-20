#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>

pthread_t threads[100];
int arr[100];

void *thread_func(void *arg) {
  int i = (int)arg;
  arr[i] = 10;
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < 100; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }

  for (int i = 0; i < 100; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
