#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("test.txt", "w");
  fclose(fp);

  free(fp);

  fp = fopen("test.txt", "r");
  fprintf(fp, "Hello, world!");
  fclose(fp);

  return 0;
}
