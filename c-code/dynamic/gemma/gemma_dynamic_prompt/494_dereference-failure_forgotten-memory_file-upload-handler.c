#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *filename = malloc(1024);
  filename = NULL;

  FILE *fp = fopen("foo.txt", "w");
  if (fp == NULL) {
    return 1;
  }

  fprintf(fp, "Hello, world!");
  fclose(fp);

  free(filename);
  return 0;
}
