#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = malloc(10);
  FILE *fp = fopen("audio.dat", "rb");
  size_t read_size = fread(buf, 1, 10, fp);

  // Out-of-bounds write vulnerability
  buf[read_size] = 0xdeadbeef;

  free(buf);
  fclose(fp);

  return 0;
}
