#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("/etc/passwd", "w");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  fprintf(fp, "Hello, world!");
  fclose(fp);

  return 0;
}
