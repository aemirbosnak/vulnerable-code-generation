#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdlib.h>

int main() {
  pthread_t threads[10];
  int *arr = (int *) malloc(10 * sizeof(int));
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, NULL, arr);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  free(arr);
  return 0;
}
