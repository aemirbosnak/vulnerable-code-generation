#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[1024];
  FILE *fp;
  char data[1024];

  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Potential buffer overflow vulnerability
  fread(data, 1, 1024, fp);

  fclose(fp);

  // Potential dereference failure
  printf("%s", data);

  return 0;
}
