#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int i, j, x, y;
  int img_width = 1024;
  int img_height = 512;
  int pixel_data[img_width * img_height];

  // Load pixel data from image file (this code assumes the image data is already stored in pixel_data)

  // Apply image processing filter
  for (y = 0; y < img_height; y++) {
    for (x = 0; x < img_width; x++) {
      int r = pixel_data[y * img_width + x] * 2;
      pixel_data[y * img_width + x] = r;
    }
  }

  // Save pixel data to image file (this code assumes the image data has already been saved to pixel_data)

  return 0;
}
