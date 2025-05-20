#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int *pool = NULL;
  int size = 0;

  pool = malloc(10 * sizeof(int));
  if (pool == NULL) {
    return 1;
  }

  size = 10;
  pool[size - 1] = 5;

  printf("%d", pool[size - 1]);

  free(pool);

  return 0;
}
