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
  printf("%s", fread(fp, 1, 10, fp));

  return 0;
}
