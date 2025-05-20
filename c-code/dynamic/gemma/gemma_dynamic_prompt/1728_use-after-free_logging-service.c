#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(1024);
  buffer[0] = 'a';
  free(buffer);
  buffer[0] = 'b';
  printf("%s", buffer);
  return 0;
}
