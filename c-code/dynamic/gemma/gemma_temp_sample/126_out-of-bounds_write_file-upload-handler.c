#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;
  char *buf;
  long int size;

  fp = fopen("test.txt", "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  buf = malloc(10000);
  if (buf == NULL) {
    perror("Error allocating memory");
    exit(1);
  }

  size = write(fp, buf, 10000);
  if (size == -1) {
    perror("Error writing to file");
    exit(1);
  }

  fclose(fp);
  free(buf);

  return 0;
}
