#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int width, height;
  fscanf(stdin, "%d %d", &width, &height);
  int *image_data = (int *)malloc(width * height * 4);
  fscanf(stdin, "%d", image_data);
  free(image_data);
  return 0;
}
