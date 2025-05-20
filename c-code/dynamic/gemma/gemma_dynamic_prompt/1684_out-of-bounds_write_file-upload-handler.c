#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* file = fopen("my_file.txt", "w");
  fprintf(file, "Hello, world!");
  fclose(file);

  return 0;
}
