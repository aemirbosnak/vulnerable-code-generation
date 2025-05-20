#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[10];
int jobs[10] = {0};

void* worker(void* arg) {
  int idx = (int)arg;
  while (jobs[idx] != -1) {
    sleep(1);
  }
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, worker, (void*)i);
  }

  for (int i = 0; i < 10; i++) {
    jobs[i] = rand() % 10;
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
