#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

pthread_t threads[MAX_THREADS];
char buffer[BUFFER_SIZE];

void* thread_func(void* thread_id) {
  char* command = (char*)malloc(BUFFER_SIZE);
  gets(command);

  // Overflow the buffer
  command = realloc(command, BUFFER_SIZE * 2);
  gets(command);

  free(command);
  pthread_exit(NULL);
}

int main() {
  int i;
  pthread_t thread_id;

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void*)i);
  }

  for (i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
