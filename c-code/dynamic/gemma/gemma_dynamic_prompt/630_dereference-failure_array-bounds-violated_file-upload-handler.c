#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(10);
  FILE *f = fopen("test.txt", "w");
  unsigned int i = 0;

  for (i = 0; i < 100; i++) {
    buf[i] = 'A';
  }

  fprintf(f, "%s", buf);
  fclose(f);

  return 0;
}
