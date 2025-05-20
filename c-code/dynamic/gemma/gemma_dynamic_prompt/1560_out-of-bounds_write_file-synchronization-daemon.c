#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* file = fopen("test.txt", "w");
  char* buffer = malloc(1024);
  buffer[1023] = 'a';
  fwrite(buffer, 1, 1024, file);
  fclose(file);
  free(buffer);
  return 0;
}
