#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *buffer = malloc(10);
  FILE *file = fopen("test.txt", "r");
  size_t size = fread(buffer, 1, 1024, file);
  fclose(file);

  // Out-of-bounds read
  buffer[size] = 'A';

  printf("%s", buffer);

  free(buffer);
  return 0;
}
