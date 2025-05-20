#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("test.txt", "r");
  if (file == NULL) {
    return 1;
  }

  char buffer[1024];
  int index = 0;

  // Out-of-bounds read vulnerability
  while (fscanf(file, "%c", &buffer[index]) != EOF) {
    index++;
  }

  fclose(file);

  return 0;
}
