//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Load the image
  FILE *fp = fopen("image.bmp", "rb");
  if (!fp) {
    printf("Error opening image file.\n");
    return 1;
  }

  // Read the header
  unsigned char header[54];
  fread(header, 1, 54, fp);

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * 3);

  // Read the image data
  fread(data, 1, width * height * 3, fp);

  // Close the image file
  fclose(fp);

  // Flip the image vertically
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      for (int i = 0; i < 3; i++) {
        unsigned char temp = data[y * width * 3 + x * 3 + i];
        data[y * width * 3 + x * 3 + i] = data[(height - y - 1) * width * 3 + x * 3 + i];
        data[(height - y - 1) * width * 3 + x * 3 + i] = temp;
      }
    }
  }

  // Change the brightness and contrast
  float brightness = 1.2;
  float contrast = 1.5;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      for (int i = 0; i < 3; i++) {
        int value = data[y * width * 3 + x * 3 + i];
        value = (value - 128) * contrast + 128;
        value = value * brightness;
        if (value < 0) value = 0;
        if (value > 255) value = 255;
        data[y * width * 3 + x * 3 + i] = value;
      }
    }
  }

  // Save the image
  fp = fopen("image_out.bmp", "wb");
  if (!fp) {
    printf("Error opening output image file.\n");
    return 1;
  }

  // Write the header
  fwrite(header, 1, 54, fp);

  // Write the image data
  fwrite(data, 1, width * height * 3, fp);

  // Close the image file
  fclose(fp);

  // Free the memory
  free(data);

  return 0;
}