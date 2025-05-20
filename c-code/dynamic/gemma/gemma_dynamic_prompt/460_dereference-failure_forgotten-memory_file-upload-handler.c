#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char *buf = NULL;
  int size = 0;

  // Allocate memory for file data
  buf = malloc(size);

  // Upload file data, ignoring size limitations
  FILE *fp = fopen("large_file.bin", "r");
  size = fread(buf, 1, 1000000, fp);
  fclose(fp);

  // Free memory, but not the memory allocated for file data
  free(buf);

  return 0;
}
