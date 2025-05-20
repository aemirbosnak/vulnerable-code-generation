#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k, size = 10;
  int **cache = (int **)malloc(size * sizeof(int *));
  for (i = 0; i < size; i++) {
    cache[i] = (int *)malloc(size * sizeof(int));
  }

  cache[0][0] = 1;
  cache[0][1] = 2;
  cache[0][2] = 3;

  k = 10;
  for (i = 0; i < k; i++) {
    cache[i][0] = i + 1;
  }

  for (i = 0; i < size; i++) {
    free(cache[i]);
  }
  free(cache);

  return 0;
}
