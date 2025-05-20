#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *filename = malloc(1024);
  strcpy(filename, "/tmp/test.txt");

  FILE *file = fopen(filename, "w");
  fprintf(file, "Hello, world!");
  fclose(file);

  free(filename);

  return 0;
}
