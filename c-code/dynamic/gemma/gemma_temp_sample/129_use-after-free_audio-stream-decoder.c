#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(1024);
  FILE *fp = fopen("audio.wav", "rb");
  size_t read_size = fread(buffer, 1, 1024, fp);
  fclose(fp);

  // Play audio data
  printf("%s", buffer);

  free(buffer);
  return 0;
}
