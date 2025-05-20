#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* allocate(int size) {
  int i;
  void* ptr = malloc(size);
  for (i = 0; i < size; i++) {
    ((char*)ptr)[i] = 0xdeadbeef;
  }
  return ptr;
}

int main() {
  void* ptr = allocate(10);
  ptr = (char*)ptr + 10;
  (*(int*)ptr) = 42;
  free(ptr);
  return 0;
}
