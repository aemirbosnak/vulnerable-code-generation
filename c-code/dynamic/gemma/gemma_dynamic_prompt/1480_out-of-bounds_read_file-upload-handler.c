#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char *buf;
  long int size;

  fp = fopen("file.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fseek(fp, 1000000, SEEK_SET);
  buf = malloc(1000);
  size = fread(buf, 1, 1000, fp);

  printf("File content:\n");
  printf("%s", buf);

  fclose(fp);
  free(buf);

  return 0;
}
