#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  char *pool = NULL;
  int size = 0;

  gets(pool); // Overflow on gets

  size = strlen(pool) + 1;
  pool = realloc(pool, size);

  free(pool);

  return 0;
}
