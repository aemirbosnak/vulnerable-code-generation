#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *filename = malloc(1024);
  FILE *fp = fopen("vulnerable_file.txt", "w");
  filename[0] = '\0';
  fprintf(fp, "This is the content of the vulnerable file.");
  fclose(fp);

  return 0;
}
