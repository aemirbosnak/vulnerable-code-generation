#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char *buffer;
  int size = 1024 * 10; // 10 MB

  buffer = malloc(size);
  fp = fopen("test.txt", "w");

  // Write data to file, out of bounds
  fwrite(buffer, size, 1, fp);

  fclose(fp);
  free(buffer);

  return 0;
}
