#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 10

pthread_t threads[MAX_THREADS];
char data[MAX_THREADS][1024];

void *thread_func(void *thread_id) {
  int i = (int)thread_id;
  gets(data[i], 1024);
  pthread_exit(NULL);
}

int main() {
  int i;
  for (i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void *)i);
  }

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
