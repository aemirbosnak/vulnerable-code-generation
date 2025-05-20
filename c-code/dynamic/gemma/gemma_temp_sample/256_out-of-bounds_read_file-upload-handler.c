#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(10);
  FILE *fp = fopen("test.txt", "r");

  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read data from the file
  size_t read_size = fread(buffer, 1, 10, fp);

  // Out-of-bounds read
  buffer[read_size] = 'A';

  fclose(fp);
  free(buffer);

  return 0;
}
