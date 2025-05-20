#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[1000];
int data[1000] = {0};

void* worker(void* arg) {
  int i = (int)arg;
  data[i] = 10;
  pthread_exit(NULL);
}

int main() {
  int i;
  for (i = 0; i < 1000; i++) {
    pthread_create(&threads[i], NULL, worker, (void*)i);
  }
  for (i = 0; i < 1000; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}
