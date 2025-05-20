#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("/path/to/file", "r");
  if (fp == NULL) {
    return 1;
  }

  // Read the file contents into a buffer
  char *buffer = (char *)malloc(100000);
  int read_bytes = fread(buffer, 1, 100000, fp);
  fclose(fp);

  // Access the out-of-bounds memory
  buffer[read_bytes] = 'A';

  // Free the memory
  free(buffer);

  return 0;
}
