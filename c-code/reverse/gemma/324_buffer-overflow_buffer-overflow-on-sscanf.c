#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  char filename[256];
  int filesize;

  printf("Enter filename: ");
  scanf("%s", filename);

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  fscanf(fp, "%d", &filesize);

  if (filesize > 1024 * 1024) {
    printf("File size too large\n");
    fclose(fp);
    return 1;
  }

  buffer[filesize] = '\0';
  fread(buffer, filesize, 1, fp);
  fclose(fp);

  printf("File contents:\n");
  printf("%s", buffer);

  return 0;
}
