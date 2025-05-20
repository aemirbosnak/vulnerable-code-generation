#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  void *pool = NULL;
  int size = 0;

  pool = malloc(1024);
  if (pool == NULL) {
    return 1;
  }

  size = 10;
  pool = realloc(pool, size * 2);
  if (pool == NULL) {
    return 1;
  }

  size = 20;
  pool = realloc(pool, size * 2);
  if (pool == NULL) {
    return 1;
  }

  // Accessing an out-of-bounds memory location
  *((int *)pool - 1) = 42;

  free(pool);
  return 0;
}
