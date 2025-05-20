#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  FILE *file;

  file = fopen("file.txt", "r");
  fscanf(file, "%s", buffer);
  fclose(file);

  printf("%s", buffer);

  return 0;
}
