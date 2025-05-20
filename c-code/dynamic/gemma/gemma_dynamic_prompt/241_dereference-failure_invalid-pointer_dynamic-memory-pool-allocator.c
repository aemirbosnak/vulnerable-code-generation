#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  return ptr;
}

int main() {
  void* ptr = alloc(10);
  *(int*)ptr = 5;
  free(ptr);
  return 0;
}
