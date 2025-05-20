#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* buffer = NULL;
  int size = 0;
  buffer = (int*)malloc(size);
  *buffer = 10;
  printf("%d", *buffer);
  free(buffer);
  return 0;
}
