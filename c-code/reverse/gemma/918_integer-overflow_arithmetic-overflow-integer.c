#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  int i = 0;
  char filename[256];
  FILE *fp;

  for (i = 0; i < 1000; i++) {
    sprintf(filename, "backup_%d.txt", i);
    fp = fopen(filename, "w");
    fclose(fp);
  }

  return 0;
}
