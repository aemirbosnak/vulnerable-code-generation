#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  FILE* file = fopen("plugin.txt", "r");
  fscanf(file, "%s", buffer);
  fclose(file);

  printf("The content of the file is: %s", buffer);

  return 0;
}
