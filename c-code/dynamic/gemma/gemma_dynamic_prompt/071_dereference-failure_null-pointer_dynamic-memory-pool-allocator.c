#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

void *allocate(int size) {
  void *ptr = malloc(size);
  return ptr;
}

void free(void *ptr) {
  free(ptr);
}

int main() {
  int *arr = allocate(10);
  free(arr);
  return 0;
}
