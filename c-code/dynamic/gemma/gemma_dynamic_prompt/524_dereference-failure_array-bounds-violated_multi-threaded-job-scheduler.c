#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t threads[10];
int data[10] = {0};

void* worker(void* arg) {
  int idx = (int)arg;
  data[idx] = 10;
  pthread_exit(NULL);
}

int main() {
  pthread_mutex_init(NULL, NULL);
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, worker, (void*)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < 10; i++) {
    printf("Data[%d] = %d\n", i, data[i]);
  }

  return 0;
}
