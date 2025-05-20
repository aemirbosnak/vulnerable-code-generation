#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* my_malloc(size_t size) {
  void* ptr = malloc(size);
  if (ptr) {
    *(int*)ptr = -1; // Out of bounds write vulnerability
  }
  return ptr;
}

int main() {
  void* ptr = my_malloc(10);
  *(int*)ptr = 42; // Out of bounds write
  free(ptr);
  return 0;
}
