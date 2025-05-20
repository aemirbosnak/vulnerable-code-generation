#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  FILE* file = fopen("test.txt", "w");
  unsigned int file_size = 1024 * 1024;
  unsigned char* data = malloc(file_size);
  fread(data, file_size, 1, file);
  fwrite(data, file_size, 1, file);
  fclose(file);
  free(data);
  return 0;
}
