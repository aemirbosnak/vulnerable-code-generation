#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = NULL;
  int size = 0;
  FILE *fp = fopen("test.txt", "w");

  if (fp == NULL) {
    return 1;
  }

  // Allocate memory for the buffer.
  buf = malloc(size);

  // Write data to the file.
  fprintf(fp, "This is the data that will be written to the file.");

  // Write beyond the buffer bounds.
  buf[size] = 'A';

  fclose(fp);
  free(buf);

  return 0;
}
