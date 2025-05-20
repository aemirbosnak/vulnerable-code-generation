#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[10];
int shared_arr[10];

void *thread_func(void *thread_id) {
  int i = (int)thread_id;
  shared_arr[i] = 10;
  return NULL;
}

int main() {
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);

  return 0;
}
