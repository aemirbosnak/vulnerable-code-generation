#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 0, b = 0, c = 0;
  FILE *f = fopen("test.txt", "w");

  a = 1000000000;
  b = a + 1;
  c = b * 2;

  fprintf(f, "%d", c);
  fclose(f);

  return 0;
}
