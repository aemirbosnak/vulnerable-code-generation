#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
  char buffer[10];
  fscanf(stdin, "%s", buffer);
  pthread_exit(0);
}

int main() {
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, NULL);
  }
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
