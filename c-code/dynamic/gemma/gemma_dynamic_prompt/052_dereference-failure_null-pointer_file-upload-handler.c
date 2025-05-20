#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = NULL;
  char *buffer = NULL;
  size_t size = 0;

  fp = fopen("test.txt", "w");
  if (fp == NULL) {
    return 1;
  }

  buffer = malloc(size);
  if (buffer == NULL) {
    fclose(fp);
    return 1;
  }

  size = fread(buffer, 1, 10, fp);
  if (size != 10) {
    fclose(fp);
    free(buffer);
    return 1;
  }

  fprintf(fp, buffer);
  fclose(fp);
  free(buffer);

  return 0;
}
