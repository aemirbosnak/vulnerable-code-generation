//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

void convert_image_to_ascii(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      unsigned char pixel = image[y * width + x];
      char ascii = " .:-=+*#%@"[pixel / 16];
      printf("%c", ascii);
    }
    printf("\n");
  }
}

int main() {
  // Open the image file
  FILE *image_file = fopen("input.bmp", "rb");
  if (image_file == NULL) {
    printf("Error opening the image file.\n");
    return 1;
  }

  // Read the header information
  unsigned char header[14];
  fread(header, 14, 1, image_file);

  // Check if the file is a valid BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    printf("Error: The file is not a valid BMP file.\n");
    fclose(image_file);
    return 1;
  }

  // Read the width and height of the image
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Read the image data
  unsigned char *image = malloc(width * height);
  fread(image, width * height, 1, image_file);

  // Close the image file
  fclose(image_file);

  // Convert the image to ASCII art
  convert_image_to_ascii(image, width, height);

  // Free the allocated memory
  free(image);

  return 0;
}