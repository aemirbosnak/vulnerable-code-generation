#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];
char data[MAX_THREADS][1024];

void* thread_function(void* thread_id) {
  int id = (int)thread_id;
  scanf("%s", data[id]);
  return NULL;
}

int main() {
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void*)i);
  }

  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
