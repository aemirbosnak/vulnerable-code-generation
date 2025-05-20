//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image
void flip_image(unsigned char *image, int width, int height) {
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      unsigned char temp = image[i * width + j];
      image[i * width + j] = image[(height - 1 - i) * width + j];
      image[(height - 1 - i) * width + j] = temp;
    }
  }
}

// Function to change the brightness of an image
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

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
  float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int new_value = round(factor * (image[i * width + j] - 128) + 128);
      if (new_value < 0) {
        new_value = 0;
      } else if (new_value > 255) {
        new_value = 255;
      }
      image[i * width + j] = new_value;
    }
  }
}

// Main function
int main() {
  // Read the image from a file
  FILE *file = fopen("image.bmp", "rb");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);

  // Allocate memory for the image data
  unsigned char *image = malloc(width * height * sizeof(unsigned char));
  if (image == NULL) {
    perror("Error allocating memory");
    return 1;
  }

  // Read the image data
  fread(image, sizeof(unsigned char), width * height, file);

  // Flip the image
  flip_image(image, width, height);

  // Change the brightness of the image
  change_brightness(image, width, height, 50);

  // Change the contrast of the image
  change_contrast(image, width, height, 1.5);

  // Write the image to a new file
  FILE *new_file = fopen("new_image.bmp", "wb");
  if (new_file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Write the image dimensions
  fwrite(&width, sizeof(int), 1, new_file);
  fwrite(&height, sizeof(int), 1, new_file);

  // Write the image data
  fwrite(image, sizeof(unsigned char), width * height, new_file);

  // Free the memory
  free(image);

  // Close the files
  fclose(file);
  fclose(new_file);

  return 0;
}