#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("test.txt", "w");
  int offset = 1000000;
  char buffer[1024];

  memset(buffer, 'a', 1024);
  buffer[offset] = 'b';

  fwrite(buffer, 1, 1024, file);
  fclose(file);

  return 0;
}
