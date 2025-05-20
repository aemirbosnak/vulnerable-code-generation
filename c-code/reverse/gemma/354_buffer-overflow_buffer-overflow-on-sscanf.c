#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char filename[256];
  scanf("%s", filename);
  int width, height;
  sscanf(filename, "%dx%d", &width, &height);
  printf("Image dimensions: %dx%d", width, height);
  return 0;
}
