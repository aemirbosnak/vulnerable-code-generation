#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  return ptr;
}

int main() {
  int* arr = alloc(10);
  *arr = 5;
  free(arr);
  return 0;
}
