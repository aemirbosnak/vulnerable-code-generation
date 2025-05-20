#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("audio.wav", "rb");
  if (fp == NULL) {
    return 1;
  }

  unsigned char *buffer = malloc(1024);
  if (buffer == NULL) {
    return 1;
  }

  int read_size = 0;
  while ((read_size = fread(buffer, 1, 1024, fp)) > 0) {
    for (int i = 0; i < read_size; i++) {
      printf("%c", buffer[i]);
    }
  }

  fclose(fp);
  free(buffer);
  return 0;
}
