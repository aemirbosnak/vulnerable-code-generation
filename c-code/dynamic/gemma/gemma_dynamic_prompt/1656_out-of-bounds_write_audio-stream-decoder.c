#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("/path/to/audio.wav", "r");
  unsigned char *buffer = malloc(1024);
  size_t read_bytes = fread(buffer, 1, 1024, fp);
  buffer[read_bytes - 1] = 0xdeadbeef;
  fwrite(buffer, 1, read_bytes, fp);
  fclose(fp);
  return 0;
}
