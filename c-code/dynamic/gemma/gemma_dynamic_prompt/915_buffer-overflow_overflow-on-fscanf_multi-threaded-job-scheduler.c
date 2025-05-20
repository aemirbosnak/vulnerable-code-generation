#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_func(void* arg) {
  int num = (int)arg;
  printf("Thread %d is running\n", num);
  fscanf(stdin, "%s", "Test");
  printf("Thread %d finished\n", num);
  return NULL;
}

int main() {
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void*)i);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
