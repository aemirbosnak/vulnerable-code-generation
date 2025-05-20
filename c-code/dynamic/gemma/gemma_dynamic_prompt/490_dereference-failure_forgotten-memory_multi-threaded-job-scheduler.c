#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func(void *arg) {
  int *ptr = (int *)arg;
  int value = *ptr;
  printf("Thread %d: value = %d\n", *ptr, value);
  free(ptr);
  return NULL;
}

int main() {
  pthread_t thread_id[10];
  int i, err;
  int *thread_args[10];

  for (i = 0; i < 10; i++) {
    thread_args[i] = malloc(sizeof(int));
    *thread_args[i] = i;
  }

  for (i = 0; i < 10; i++) {
    err = pthread_create(&thread_id[i], NULL, thread_func, thread_args[i]);
    if (err) {
      printf("Error creating thread: %s\n", strerror(err));
      exit(1);
    }
  }

  for (i = 0; i < 10; i++) {
    pthread_join(thread_id[i], NULL);
  }

  return 0;
}
