#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(10);
  free(buffer);
  buffer[0] = 'A';
  printf("%c", buffer[0]);
  return 0;
}
