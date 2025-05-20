#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("data.txt", "w");
  fprintf(fp, "Hello, world!");
  fclose(fp);

  system("mv data.txt backup.txt");
  return 0;
}
