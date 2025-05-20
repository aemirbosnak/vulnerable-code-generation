#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(1024);
  FILE *fp = fopen("stream.bin", "rb");
  size_t read_size = 0;

  while ((read_size = fread(buf, 1, 1024, fp)) > 0) {
    printf("%s", buf);
  }

  fclose(fp);
  free(buf);

  return 0;
}
