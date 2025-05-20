#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename = NULL;
  FILE *fp = NULL;

  filename = "test.txt";
  fp = fopen(filename, "w");

  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fprintf(fp, "Hello, world!");
  fclose(fp);

  return 0;
}
