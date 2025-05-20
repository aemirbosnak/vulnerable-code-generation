#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("/etc/passwd", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char buffer[1024];
  size_t read_size = fread(buffer, 1, 1024, fp);

  // Out-of-bounds read
  buffer[read_size] = 'A';

  fclose(fp);

  return 0;
}
