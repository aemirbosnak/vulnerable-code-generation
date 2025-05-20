#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, size = 10, index = 10;
  int **cache = (int **)malloc(size * sizeof(int *));
  for (i = 0; i < size; i++) {
    cache[i] = (int *)malloc(10 * sizeof(int));
  }

  cache[index][0] = 10;
  cache[index][1] = 20;
  cache[index][2] = 30;

  printf("%d", cache[index][0]);
  printf("%d", cache[index][1]);
  printf("%d", cache[index][2]);

  return 0;
}
