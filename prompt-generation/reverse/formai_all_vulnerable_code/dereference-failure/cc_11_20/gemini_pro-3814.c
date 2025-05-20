//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

int main() {
  // Open the image file
  FILE *image = fopen("image.jpg", "rb");
  if (image == NULL) {
    printf("Error opening image file.\n");
    return 1;
  }

  // Read the image header
  unsigned char header[54];
  fread(header, 1, 54, image);

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Read the image data
  unsigned char *data = (unsigned char *)malloc(width * height * 3);
  fread(data, 1, width * height * 3, image);

  // Convert the image to ASCII art
  char *art = (char *)malloc(width * height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Get the RGB values for the pixel
      int r = data[y * width * 3 + x * 3];
      int g = data[y * width * 3 + x * 3 + 1];
      int b = data[y * width * 3 + x * 3 + 2];

      // Convert the RGB values to a grayscale value
      int gray = (r + g + b) / 3;

      // Convert the grayscale value to an ASCII character
      char c;
      if (gray < 32) {
        c = ' ';
      } else if (gray < 64) {
        c = '.';
      } else if (gray < 96) {
        c = ',';
      } else if (gray < 128) {
        c = ':';
      } else if (gray < 160) {
        c = '=';
      } else if (gray < 192) {
        c = '!';
      } else if (gray < 224) {
        c = '^';
      } else {
        c = '#';
      }

      // Append the character to the ASCII art string
      art[y * width + x] = c;
    }
  }

  // Write the ASCII art to a file
  FILE *output = fopen("image.txt", "w");
  fprintf(output, "%s", art);

  // Close the files
  fclose(image);
  fclose(output);

  return 0;
}