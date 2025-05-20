#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

void *thread_function(void *thread_id) {
  char buffer[BUFFER_SIZE];
  scanf("%s", buffer);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void *)i);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
