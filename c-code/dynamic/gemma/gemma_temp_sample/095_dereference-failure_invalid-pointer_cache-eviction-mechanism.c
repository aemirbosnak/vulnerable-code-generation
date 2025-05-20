#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = NULL;
  *ptr = 10;
  free(ptr);
  printf("Hello, world!");
  return 0;
}
