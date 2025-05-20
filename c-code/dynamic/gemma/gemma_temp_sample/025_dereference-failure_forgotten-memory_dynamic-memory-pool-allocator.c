#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  void *pool = malloc(1024);
  free(pool);
  int *ptr = (int *)pool;
  *ptr = 42;
  return 0;
}
