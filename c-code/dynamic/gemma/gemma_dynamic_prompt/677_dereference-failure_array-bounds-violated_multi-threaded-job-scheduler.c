#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  pthread_t t1, t2;
  int arr[5] = {0, 1, 2, 3, 4};

  pthread_create(&t1, NULL, (void *)arr, NULL);
  pthread_create(&t2, NULL, (void *)arr, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
