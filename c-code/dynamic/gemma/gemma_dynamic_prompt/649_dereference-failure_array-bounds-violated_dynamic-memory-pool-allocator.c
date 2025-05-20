#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc(int size) {
  int i = 0;
  void* ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  for (i = 0; i < size; i++) {
    *((int*)ptr + i) = 0;
  }
  return ptr;
}

int main() {
  void* ptr = alloc(10);
  ptr = (int*)ptr + 10;
  *((int*)ptr) = 5;
  free(ptr);
  return 0;
}
