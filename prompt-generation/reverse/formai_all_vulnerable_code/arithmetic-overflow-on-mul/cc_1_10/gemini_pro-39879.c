//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontal(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[y * width + width - x - 1];
      image[y * width + width - x - 1] = temp;
    }
  }
}

// Function to flip an image vertically
void flipVertical(unsigned char *image, int width, int height) {
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[(height - y - 1) * width + x];
      image[(height - y - 1) * width + x] = temp;
    }
  }
}

// Function to change the brightness of an image
void changeBrightness(unsigned char *image, int width, int height, int brightness) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int newBrightness = image[y * width + x] + brightness;
      if (newBrightness > 255) {
        newBrightness = 255;
      } else if (newBrightness < 0) {
        newBrightness = 0;
      }
      image[y * width + x] = newBrightness;
    }
  }
}

// Function to change the contrast of an image
void changeContrast(unsigned char *image, int width, int height, float contrast) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int newContrast = (image[y * width + x] - 128) * contrast + 128;
      if (newContrast > 255) {
        newContrast = 255;
      } else if (newContrast < 0) {
        newContrast = 0;
      }
      image[y * width + x] = newContrast;
    }
  }
}

int main() {
  // Read the image from a file
  FILE *file = fopen("image.bmp", "rb");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);

  // Allocate memory for the image data
  unsigned char *image = malloc(width * height);
  if (image == NULL) {
    perror("Error allocating memory");
    fclose(file);
    return EXIT_FAILURE;
  }

  // Read the image data from the file
  fread(image, sizeof(unsigned char), width * height, file);
  fclose(file);

  // Flip the image horizontally
  flipHorizontal(image, width, height);

  // Flip the image vertically
  flipVertical(image, width, height);

  // Change the brightness of the image
  changeBrightness(image, width, height, 50);

  // Change the contrast of the image
  changeContrast(image, width, height, 1.5);

  // Write the image to a file
  file = fopen("new_image.bmp", "wb");
  if (file == NULL) {
    perror("Error opening file");
    fclose(file);
    return EXIT_FAILURE;
  }

  // Write the image dimensions to the file
  fwrite(&width, sizeof(int), 1, file);
  fwrite(&height, sizeof(int), 1, file);

  // Write the image data to the file
  fwrite(image, sizeof(unsigned char), width * height, file);
  fclose(file);

  // Free the memory allocated for the image data
  free(image);

  return EXIT_SUCCESS;
}