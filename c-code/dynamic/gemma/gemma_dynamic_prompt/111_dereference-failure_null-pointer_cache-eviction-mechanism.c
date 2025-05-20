#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void cache_eviction(char **cache, int size, int key) {
  int i = 0;
  for (i = 0; i < size; i++) {
    if (cache[i] == NULL) {
      cache[i] = malloc(sizeof(char) * 1024);
    }
    if (strcmp(cache[i], key) == 0) {
      printf("Cache hit!\n");
      return;
    }
  }

  printf("Cache miss!\n");
  cache[i] = malloc(sizeof(char) * 1024);
  strcpy(cache[i], key);
}

int main() {
  char **cache = NULL;
  int size = 10;
  int key = "foo";

  cache_eviction(cache, size, key);

  return 0;
}
