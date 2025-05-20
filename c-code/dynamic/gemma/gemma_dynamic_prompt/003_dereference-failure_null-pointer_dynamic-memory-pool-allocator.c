#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* allocate(int size) {
  void* ptr = malloc(size);
  return ptr;
}

void free(void* ptr) {
  free(ptr);
}

int main() {
  void* ptr = allocate(10);
  free(ptr);
  printf("Hello, world!");
  return 0;
}
