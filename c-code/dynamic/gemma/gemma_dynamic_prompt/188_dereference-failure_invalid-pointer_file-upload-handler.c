#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  FILE *file = fopen("file.txt", "w");
  int size = 1024 * 1024;
  unsigned char *buffer = malloc(size);
  buffer[size - 1] = 0;

  FILE *upload = fopen("upload.bin", "r");
  int read_size = fread(buffer, 1, size, upload);

  fwrite(buffer, 1, read_size, file);
  fclose(file);
  fclose(upload);

  free(buffer);
  return 0;
}
