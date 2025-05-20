#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *my_malloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  return ptr;
}

void my_free(void *ptr) {
  free(ptr);
}

int main() {
  int *arr = my_malloc(10);
  arr[10] = 5; // Buffer overflow
  my_free(arr);
  return 0;
}
