#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(10);
  strcpy(buffer, "Hello, world!");

  // Out-of-bounds write vulnerability
  buffer[10] = 'A';

  printf("%s", buffer);

  free(buffer);
  return 0;
}
