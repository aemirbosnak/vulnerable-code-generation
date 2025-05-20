#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *file = fopen("test.txt", "r");
  int size = 0;
  char *buffer = NULL;

  // Read file size
  fseek(file, 0L, SEEK_END);
  size = ftell(file) - 1;
  rewind(file);

  // Allocate memory and read file contents
  buffer = malloc(size);
  fread(buffer, size, 1, file);

  // Out-of-bounds read
  buffer[size + 1] = 0x3B;

  // Free memory and close file
  free(buffer);
  fclose(file);

  return 0;
}
