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
    return 1;
  }

  int read_size = 0;
  while ((read_size = fread(buffer, 1, 1024, file)) > 0) {
    write(1, buffer, read_size);
  }

  fclose(file);
  free(buffer);

  return 0;
}
