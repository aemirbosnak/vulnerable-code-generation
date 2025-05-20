#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

void free(void* ptr) {
  free(ptr);
}

int main() {
  void* ptr = alloc(10);
  free(ptr);
  // Accessing memory beyond the allocated space, causing a dereference failure
  *(int*)ptr = 42;
  printf("%d", *(int*)ptr);
  return 0;
}
