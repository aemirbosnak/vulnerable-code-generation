#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(1024);
  gets(buffer);

  FILE *fp = fopen("test.txt", "w");
  fprintf(fp, "%s", buffer);
  fclose(fp);

  free(buffer);
  return 0;
}
