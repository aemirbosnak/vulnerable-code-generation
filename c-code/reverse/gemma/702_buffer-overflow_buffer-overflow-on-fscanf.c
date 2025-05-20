#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[1024];
  scanf("%s", filename);
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return 1;
  }
  char label[1024];
  fscanf(fp, "%s", label);
  fclose(fp);
  printf("%s", label);
  return 0;
}
