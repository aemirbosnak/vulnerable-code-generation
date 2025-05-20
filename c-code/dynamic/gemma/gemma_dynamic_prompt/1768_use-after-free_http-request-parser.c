#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(10);
  free(buffer);
  buffer[0] = 'H';
  printf("%s", buffer);
  return 0;
}
