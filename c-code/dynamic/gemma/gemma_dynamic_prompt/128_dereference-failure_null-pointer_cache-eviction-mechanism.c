#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  void **cache = NULL;
  cache = (void **)malloc(10 * sizeof(void *));
  cache[0] = NULL;
  cache[1] = NULL;
  cache[2] = NULL;
  cache[3] = NULL;
  cache[4] = NULL;
  cache[5] = NULL;
  cache[6] = NULL;
  cache[7] = NULL;
  cache[8] = NULL;
  cache[9] = NULL;

  cache[10] = (void *)malloc(10);
  cache[10] = NULL;

  free(cache);
  return 0;
}
