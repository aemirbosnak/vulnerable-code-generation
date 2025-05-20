#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void evictCache(int **cache, int size, int key) {
  int i;
  for (i = 0; i < size; i++) {
    if (*cache[i] == key) {
      cache[i] = NULL;
      return;
    }
  }
  return;
}

int main() {
  int **cache = NULL;
  int size = 0;
  int key = 10;

  evictCache(&cache, size, key);

  return 0;
}
