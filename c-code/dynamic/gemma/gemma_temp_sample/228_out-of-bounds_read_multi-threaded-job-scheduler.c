#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
  int* shared_ptr = (int*)arg;
  int index = *shared_ptr;
  read(index, NULL, 0); // Out of bounds read
  pthread_exit(NULL);
}

int main() {
  int shared_arr[] = {1, 2, 3, 4, 5};
  pthread_t threads[2];

  for (int i = 0; i < 2; i++) {
    pthread_create(&threads[i], NULL, thread_func, (void*)&shared_arr[i]);
  }

  for (int i = 0; i < 2; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
