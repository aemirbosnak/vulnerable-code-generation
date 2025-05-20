#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char buffer[10];
  char filename[256];

  printf("Enter the filename of the PGM image file: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fscanf(fp, "%s", buffer);
  fclose(fp);

  return 0;
}
