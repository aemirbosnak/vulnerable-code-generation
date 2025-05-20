#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *filename = malloc(1024);
  FILE *fp = fopen("foo.txt", "w");

  if (filename == NULL || fp == NULL) {
    exit(1);
  }

  filename[0] = '\0';
  fprintf(fp, "Hello, world!");

  fclose(fp);
  free(filename);

  return 0;
}
