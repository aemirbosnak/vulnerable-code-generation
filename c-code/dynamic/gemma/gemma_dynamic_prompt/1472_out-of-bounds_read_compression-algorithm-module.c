#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("test.txt", "r");
  char *buffer = NULL;
  int size = 0;

  // Read file size
  fseek(fp, 0L, SEEK_END);
  size = ftell(fp);

  // Allocate memory for buffer
  buffer = malloc(size);

  // Read file contents
  rewind(fp);
  fread(buffer, size, 1, fp);

  // Out-of-bounds read
  buffer[size] = 0xDEADBEEF;

  // Print buffer contents
  printf("%s", buffer);

  fclose(fp);
  free(buffer);

  return 0;
}
