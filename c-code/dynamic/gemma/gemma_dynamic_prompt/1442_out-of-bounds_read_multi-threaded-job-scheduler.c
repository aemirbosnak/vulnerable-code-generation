#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_func(void *arg) {
  int *ptr = (int *)arg;
  int index = *ptr;
  read(index, NULL, 0);
  return NULL;
}

int main() {
  pthread_t threads[10];
  int i;
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, &arr[i]);
  }

  for (i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
