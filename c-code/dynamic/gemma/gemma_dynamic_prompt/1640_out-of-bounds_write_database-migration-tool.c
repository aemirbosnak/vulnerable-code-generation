#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("test.txt", "w");
  unsigned int offset = 0x1000;
  unsigned int size = 0x1000;
  char buffer[size];

  memset(buffer, 0x42, size);
  fwrite(buffer, size, 1, file);
  fclose(file);

  return 0;
}
