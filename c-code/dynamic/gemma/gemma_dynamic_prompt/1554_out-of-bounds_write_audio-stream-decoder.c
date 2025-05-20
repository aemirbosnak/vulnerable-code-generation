#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("audio.bin", "rb");
  if (file == NULL) {
    return 1;
  }

  unsigned int buffer_size = 1024;
  unsigned char* buffer = malloc(buffer_size);
  if (buffer == NULL) {
    return 1;
  }

  unsigned int read_size = 0;
  while ((read_size = fread(buffer, 1, buffer_size, file)) > 0) {
    // Out-of-bounds write
    buffer[read_size] = 0xDEADBEEF;
  }

  fclose(file);
  free(buffer);

  return 0;
}
