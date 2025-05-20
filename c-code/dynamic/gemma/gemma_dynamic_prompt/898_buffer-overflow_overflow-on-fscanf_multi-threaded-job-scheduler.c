#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];
char buffer[1024];

void* thread_function(void* thread_id) {
  scanf("%s", buffer);
  return NULL;
}

int main() {
  int i;

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, NULL);
  }

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
