#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("test.txt", "w");
  unsigned int offset = 0x10000;
  char buffer[1024];

  memset(buffer, 0x42, 1024);
  buffer[offset] = 0x3B;

  fwrite(buffer, 1, 1024, file);
  fclose(file);

  return 0;
}
