#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *cache = NULL;
  int size = 0;

  gets(cache);

  size = strlen(cache) + 1;
  cache = realloc(cache, size);

  cache[size - 1] = '\0';

  printf("%s\n", cache);

  return 0;
}
