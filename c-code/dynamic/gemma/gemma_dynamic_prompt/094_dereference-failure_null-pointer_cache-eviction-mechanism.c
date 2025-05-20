#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  void **cache = NULL;
  cache = (void **)malloc(10 * sizeof(void *));
  cache[0] = NULL;
  cache[1] = NULL;

  cache[2] = (void *)malloc(10 * sizeof(int));
  cache[3] = (void *)malloc(10 * sizeof(int));
  cache[4] = (void *)malloc(10 * sizeof(int));

  int **data = (int **)cache[2];
  data[0] = 10;
  data[1] = 20;
  data[2] = 30;

  free(cache[3]);
  free(cache[2]);

  return 0;
}
