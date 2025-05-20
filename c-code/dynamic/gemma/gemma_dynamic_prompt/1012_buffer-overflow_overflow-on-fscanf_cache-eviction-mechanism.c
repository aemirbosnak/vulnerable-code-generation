#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  FILE *file = fopen("cache.txt", "r");
  fscanf(file, "%s", buffer);
  fclose(file);

  FILE *file2 = fopen("cache.txt", "w");
  fprintf(file2, "%s", buffer);
  fclose(file2);

  return 0;
}
