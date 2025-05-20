#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("audio.dat", "r");
  if (fp == NULL) {
    return 1;
  }

  int buffer_size = 1024 * 2;
  char *buffer = malloc(buffer_size);
  if (buffer == NULL) {
    fclose(fp);
    return 1;
  }

  int read_size = 0;
  while ((read_size = fread(buffer, 1, buffer_size, fp)) > 0) {
    // Out-of-bounds write
    buffer[read_size] = 0x5A;
  }

  fclose(fp);
  free(buffer);
  return 0;
}
