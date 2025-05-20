#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  // Image data
  unsigned char image[1024];

  // Read image data
  FILE* file = fopen("image.pgm", "r");
  fread(image, 1, 1024, file);
  fclose(file);

  // Adjust brightness and contrast
  for (int i = 0; i < 1024; i++) {
    image[i] = (image[i] * 1.2) + 50;
    if (image[i] > 255) image[i] = 255;
  }

  // Horizontal flip
  for (int i = 0; i < 1024; i++) {
    image[i] = image[1023 - i];
  }

  // Vertical flip
  for (int i = 0; i < 1024; i++) {
    image[i] = image[i * 2];
  }

  // Write image data to file
  file = fopen("processed_image.pgm", "w");
  fwrite(image, 1, 1024, file);
  fclose(file);

  return 0;
}
