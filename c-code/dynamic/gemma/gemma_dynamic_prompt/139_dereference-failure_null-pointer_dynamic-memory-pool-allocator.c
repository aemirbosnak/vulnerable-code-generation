#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *allocate(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  return ptr;
}

int main() {
  void *ptr = allocate(10);
  *(int *)ptr = 10;
  free(ptr);
  return 0;
}
