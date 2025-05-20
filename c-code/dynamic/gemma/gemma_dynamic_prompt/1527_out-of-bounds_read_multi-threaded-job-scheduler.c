#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

pthread_t threads[10];
int data[1000];

void* thread_function(void* arg) {
  int index = (int)arg;
  data[index] = 10;
  pthread_exit(NULL);
}

int main() {
  for(int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void*)i);
  }

  for(int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
