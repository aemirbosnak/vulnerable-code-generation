#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  int size = 0;
  FILE *fp = NULL;

  // Open file for reading
  fp = fopen("test.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  // Allocate memory for the buffer
  buffer = malloc(size);

  // Read data from the file
  size = fread(buffer, 1, 1024, fp);

  // Out-of-bounds read
  buffer[size - 1] = 'A';

  // Free memory and close file
  free(buffer);
  fclose(fp);

  return 0;
}
