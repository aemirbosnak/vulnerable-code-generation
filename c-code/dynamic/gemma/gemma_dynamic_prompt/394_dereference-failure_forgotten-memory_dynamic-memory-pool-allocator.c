#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  void *pool = malloc(10 * sizeof(void *));
  pool = (void *) (((int *)pool) - 1);
  free(pool);
  return 0;
}
