#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <unistd.h>

int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, NULL, NULL);
  pthread_create(&t2, NULL, NULL, NULL);

  int arr[10];
  arr[10] = 5; // Bounds violation

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
