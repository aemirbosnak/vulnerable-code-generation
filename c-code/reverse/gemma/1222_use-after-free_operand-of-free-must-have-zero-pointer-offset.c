#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* alloc_protected(size_t size) {
  return malloc(size);
}

void free_protected(void* ptr, size_t size) {
  free((void*) ((size_t)ptr & ~size));
}

int main() {
  void* ptr = alloc_protected(10);
  free_protected(ptr, 5);
  // Use-after-free vulnerability: Accessing memory beyond the freed portion
  *(int*)ptr = 10;
  return 0;
}
