#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[10];
int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void* thread_function(void* arg) {
  int index = (int)arg;
  sleep(data[index]);
  pthread_exit(NULL);
}

int main() {
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void*)i);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
