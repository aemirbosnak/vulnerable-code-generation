#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char* buffer = malloc(1024);
  buffer[0] = 'a';
  free(buffer);

  return 0;
}
