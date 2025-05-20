#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("test.txt", "r");
  int offset = 1000000;
  char buffer[1024];
  fseek(file, offset, SEEK_SET);
  fread(buffer, 1, 1024, file);
  printf("%s", buffer);
  fclose(file);
  return 0;
}
