#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* allocate(int size) {
  void* ptr = malloc(size);
  if (ptr) {
    return ptr;
  } else {
    return NULL;
  }
}

void free(void* ptr) {
  free(ptr);
}

int main() {
  int* arr = allocate(10);
  arr[10] = 5;
  free(arr);
  return 0;
}
