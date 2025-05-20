#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("data.txt", "w");
  fprintf(file, "Hello, world!");
  fclose(file);
  system("rm data.txt");
  return 0;
}
