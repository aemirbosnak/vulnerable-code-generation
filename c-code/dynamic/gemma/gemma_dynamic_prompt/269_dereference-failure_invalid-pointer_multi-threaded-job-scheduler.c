#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
  int* ptr = (int*)arg;
  printf("Thread %d: Trying to dereference pointer %p\n",pthread_self(), ptr);
  *ptr = 10;
  return NULL;
}

int main() {
  pthread_t threads[10];
  int i;
  for(i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void*)&threads[i]);
  }
  pthread_join(threads[0], NULL);
  return 0;
}
