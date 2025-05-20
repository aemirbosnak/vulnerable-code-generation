#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void* thread_function(void* ptr) {
  int* number = (int*)ptr;
  sleep(1);
  printf("Thread %d: Hello, world!", *number);
  return NULL;
}

int main() {
  pthread_t threads[10];
  int i;
  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void*)i);
  }
  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
