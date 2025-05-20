//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[y * width + width - x - 1];
      image[y * width + width - x - 1] = temp;
    }
  }
}

// Flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[(height - y - 1) * width + x];
      image[(height - y - 1) * width + x] = temp;
    }
  }
}

// Change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel_value = image[y * width + x] + brightness;
      image[y * width + x] = (pixel_value > 255) ? 255 : (pixel_value < 0) ? 0 : pixel_value;
    }
  }
}

// Change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
  float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel_value = image[y * width + x] * factor;
      image[y * width + x] = (pixel_value > 255) ? 255 : (pixel_value < 0) ? 0 : pixel_value;
    }
  }
}

int main() {
  // Load an image from a file
  FILE *fp = fopen("image.bmp", "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the header of the image
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, fp);

  // Get the width and height of the image
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  unsigned char *image = malloc(width * height);
  if (image == NULL) {
    perror("Error allocating memory");
    return EXIT_FAILURE;
  }

  // Read the image data from the file
  fread(image, sizeof(unsigned char), width * height, fp);

  // Close the file
  fclose(fp);

  // Flip the image horizontally
  flip_horizontal(image, width, height);

  // Flip the image vertically
  flip_vertical(image, width, height);

  // Change the brightness of the image
  change_brightness(image, width, height, 50);

  // Change the contrast of the image
  change_contrast(image, width, height, 1.5);

  // Save the image to a file
  fp = fopen("new_image.bmp", "wb");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Write the header of the image
  fwrite(header, sizeof(unsigned char), 54, fp);

  // Write the image data to the file
  fwrite(image, sizeof(unsigned char), width * height, fp);

  // Close the file
  fclose(fp);

  // Free the memory allocated for the image data
  free(image);

  return EXIT_SUCCESS;
}