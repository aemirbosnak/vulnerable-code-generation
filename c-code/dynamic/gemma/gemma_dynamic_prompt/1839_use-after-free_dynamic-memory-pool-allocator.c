#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *pool_alloc(int size) {
  void *ptr = malloc(size);
  return ptr;
}

void pool_free(void *ptr) {
  free(ptr);
}

int main() {
  void *ptr = pool_alloc(10);
  pool_free(ptr);
  printf("Using the freed pointer: %p", ptr);
  return 0;
}
