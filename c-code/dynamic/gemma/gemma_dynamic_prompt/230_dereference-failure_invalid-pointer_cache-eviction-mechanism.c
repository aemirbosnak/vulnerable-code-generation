#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void cache_eviction(int *arr, int size) {
  int i = 0;
  for (i = 0; i < size; i++) {
    if (arr[i] == NULL) {
      printf("Cache eviction failure!\n");
      exit(1);
    }
  }
}

int main() {
  int arr[10] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
  cache_eviction(arr, 10);
  return 0;
}
