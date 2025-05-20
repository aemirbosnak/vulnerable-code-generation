#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  void *pool = NULL;
  int size = 0;

  // Allocate a large chunk of memory
  pool = malloc(10000);

  // Access an array beyond the bounds of the allocated memory
  *((int *)pool - 1) = 42;

  // Free the memory
  free(pool);

  return 0;
}
