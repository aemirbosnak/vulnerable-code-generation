#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  void *ptr = NULL;
  int size = 0;

  // Allocate memory
  ptr = malloc(size);
  if (ptr == NULL) {
    return 1;
  }

  // Resize memory
  ptr = realloc(ptr, size * 2);
  if (ptr == NULL) {
    return 1;
  }

  // Allocate and initialize memory
  ptr = calloc(size, 10);
  if (ptr == NULL) {
    return 1;
  }

  // Free memory
  free(ptr);

  return 0;
}
