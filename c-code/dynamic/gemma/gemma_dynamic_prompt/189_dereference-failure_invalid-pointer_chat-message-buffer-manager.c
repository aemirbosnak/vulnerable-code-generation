#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char *buffer = NULL;
  buffer = malloc(10);
  *(buffer - 1) = 'A';
  free(buffer);
  return 0;
}
