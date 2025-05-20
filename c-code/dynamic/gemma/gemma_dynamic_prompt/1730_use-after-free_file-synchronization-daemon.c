#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
  char *filename = "/tmp/test.txt";
  FILE *fp = fopen(filename, "w");
  fprintf(fp, "Hello, world!");
  fclose(fp);

  struct stat sb;
  stat(filename, &sb);
  printf("File size: %d bytes\n", sb.st_size);

  free(filename);
  return 0;
}
