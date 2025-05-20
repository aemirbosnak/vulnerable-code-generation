#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  FILE *fp;

  fp = fopen("test.txt", "w");

  fscanf(fp, "%s", buffer);

  fprintf(fp, "Content: %s", buffer);

  fclose(fp);

  return 0;
}
