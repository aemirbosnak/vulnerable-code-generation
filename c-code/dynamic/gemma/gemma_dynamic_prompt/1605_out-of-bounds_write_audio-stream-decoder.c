#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("audio.wav", "r");
  if (file == NULL) {
    return 1;
  }

  unsigned char* buffer = malloc(1024);
  if (buffer == NULL) {
    fclose(file);
    return 1;
  }

  size_t read_size = fread(buffer, 1, 1024, file);
  if (read_size != 1024) {
    fclose(file);
    free(buffer);
    return 1;
  }

  buffer[1023] = 0xdeadbeef; // Out of bounds write

  fclose(file);
  free(buffer);

  return 0;
}
