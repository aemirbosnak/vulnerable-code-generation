#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void cache_eviction(int *cache, int size, int key) {
  int i;
  for (i = 0; i < size; i++) {
    if (cache[i] == key) {
      cache[i] = -1;
      return;
    }
  }
  cache[0] = key;
}

int main() {
  int cache[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cache_eviction(cache, 10, 10);
  return 0;
}
