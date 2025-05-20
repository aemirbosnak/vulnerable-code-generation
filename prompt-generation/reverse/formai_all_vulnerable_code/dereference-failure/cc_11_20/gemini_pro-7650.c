//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read the image from a file
  FILE *fp = fopen("image.bmp", "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * 3);
  if (data == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return EXIT_FAILURE;
  }

  // Read the image data
  fread(data, 1, width * height * 3, fp);
  fclose(fp);

  // Flip the image vertically
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < 3; k++) {
        unsigned char temp = data[i * width * 3 + j * 3 + k];
        data[i * width * 3 + j * 3 + k] = data[(height - i - 1) * width * 3 + j * 3 + k];
        data[(height - i - 1) * width * 3 + j * 3 + k] = temp;
      }
    }
  }

  // Change the brightness and contrast
  float brightness = 0.5;
  float contrast = 1.5;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < 3; k++) {
        int value = data[i * width * 3 + j * 3 + k];
        value = (value - 128) * contrast + 128;
        value = value + brightness;
        if (value < 0) {
          value = 0;
        } else if (value > 255) {
          value = 255;
        }
        data[i * width * 3 + j * 3 + k] = value;
      }
    }
  }

  // Write the image to a file
  fp = fopen("output.bmp", "wb");
  if (fp == NULL) {
    perror("Error opening file");
    free(data);
    return EXIT_FAILURE;
  }

  // Write the image dimensions
  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);

  // Write the image data
  fwrite(data, 1, width * height * 3, fp);
  fclose(fp);

  // Free the memory
  free(data);

  return EXIT_SUCCESS;
}