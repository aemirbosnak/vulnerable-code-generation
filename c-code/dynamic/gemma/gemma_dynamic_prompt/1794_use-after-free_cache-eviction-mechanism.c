#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 10;
  int **cache = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++) {
    cache[i] = (int *)malloc(10 * sizeof(int));
  }

  cache[0][0] = 10;
  cache[0][1] = 20;
  cache[0][2] = 30;
  cache[1][0] = 40;
  cache[1][1] = 50;
  cache[1][2] = 60;

  free(cache[0]);
  free(cache[1]);
  free(cache);

  return 0;
}
