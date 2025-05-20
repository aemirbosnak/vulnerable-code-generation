#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(10);
  FILE *file = fopen("audio.wav", "r");
  unsigned char data[4] = { 0x5A, 0x5A, 0x5A, 0x5A };
  int i = 0;

  while (!feof(file)) {
    unsigned char read_data = fgetc(file);
    buffer[i] = read_data;
    i++;
    if (i >= 10) {
      buffer = realloc(buffer, 2 * 10);
      i = 0;
    }
  }

  buffer[i] = data[0];
  fclose(file);
  free(buffer);

  return 0;
}
