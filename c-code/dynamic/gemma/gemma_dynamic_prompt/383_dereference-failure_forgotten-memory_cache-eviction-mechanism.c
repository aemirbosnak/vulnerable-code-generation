#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *cache = NULL;
  cache = malloc(10 * sizeof(int));
  cache[0] = 10;
  cache[1] = 20;
  cache[2] = 30;

  int index = 3;
  int value = cache[index];

  // This line intentionally dereferences a null pointer, causing a crash
  printf("%d", value);

  return 0;
}
