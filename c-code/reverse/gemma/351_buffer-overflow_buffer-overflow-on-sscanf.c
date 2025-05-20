#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char filename[256];
  printf("Enter filename: ");
  scanf("%s", filename);

  // Extract image dimensions from filename
  char *dimensions = strstr(filename, ".bmp");
  dimensions = dimensions - 1;
  int width = atoi(dimensions);
  int height = atoi(dimensions + 3);

  // Print dimensions
  printf("Image dimensions: %dx%d\n", width, height);

  return 0;
}
