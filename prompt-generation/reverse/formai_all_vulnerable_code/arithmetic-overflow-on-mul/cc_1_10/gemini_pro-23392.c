//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void flip_image(unsigned char *image, int width, int height) {
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      unsigned char temp = image[i * width + j];
      image[i * width + j] = image[(height - i - 1) * width + j];
      image[(height - i - 1) * width + j] = temp;
    }
  }
}

void change_brightness(unsigned char *image, int width, int height, int brightness) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int new_value = image[i * width + j] + brightness;
      if (new_value < 0) {
        new_value = 0;
      } else if (new_value > 255) {
        new_value = 255;
      }
      image[i * width + j] = new_value;
    }
  }
}

void change_contrast(unsigned char *image, int width, int height, float contrast) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int new_value = (image[i * width + j] - 128) * contrast + 128;
      if (new_value < 0) {
        new_value = 0;
      } else if (new_value > 255) {
        new_value = 255;
      }
      image[i * width + j] = new_value;
    }
  }
}

int main() {
  // Load the image from a file
  FILE *file = fopen("image.bmp", "rb");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the header information
  unsigned char header[54];
  fread(header, 54, 1, file);

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  unsigned char *image = malloc(width * height);
  if (image == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Read the image data
  fread(image, width * height, 1, file);

  // Close the file
  fclose(file);

  // Flip the image
  flip_image(image, width, height);

  // Change the brightness
  change_brightness(image, width, height, 50);

  // Change the contrast
  change_contrast(image, width, height, 1.5);

  // Save the image to a file
  file = fopen("new_image.bmp", "wb");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Write the header information
  fwrite(header, 54, 1, file);

  // Write the image data
  fwrite(image, width * height, 1, file);

  // Close the file
  fclose(file);

  // Free the memory
  free(image);

  return 0;
}