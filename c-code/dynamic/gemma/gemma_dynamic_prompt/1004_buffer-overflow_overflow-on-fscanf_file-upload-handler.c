#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  FILE *file;

  file = fopen("test.txt", "w");
  fscanf(file, "%s", buffer);
  fclose(file);

  return 0;
}
