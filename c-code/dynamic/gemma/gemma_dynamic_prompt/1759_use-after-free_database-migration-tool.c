#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("data.txt", "w");
  fprintf(fp, "Hello, world!");
  fclose(fp);

  system("mv data.txt data.old");
  system("cp data.txt data.new");

  return 0;
}
