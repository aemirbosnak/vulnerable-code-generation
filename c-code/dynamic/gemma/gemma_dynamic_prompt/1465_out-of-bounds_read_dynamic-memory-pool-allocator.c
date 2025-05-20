#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *allocate(int size) {
  void *ptr = malloc(size);
  return ptr;
}

int main() {
  int size = 10;
  void *ptr = allocate(size);

  // Out of bounds read
  ptr = (char *)ptr - 10;
  printf("%c", *(char *)ptr);

  free(ptr);
  return 0;
}
