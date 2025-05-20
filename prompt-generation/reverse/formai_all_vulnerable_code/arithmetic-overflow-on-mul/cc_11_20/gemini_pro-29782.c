//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 320
#define HEIGHT 240

typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Pixel;

int main() {
  // Open the image file
  FILE *image = fopen("image.bmp", "rb");
  if (image == NULL) {
    printf("Error: could not open image file\n");
    return 1;
  }

  // Read the header of the image file
  unsigned char header[54];
  fread(header, 1, 54, image);

  // Get the width and height of the image
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Create a buffer to store the pixel data
  Pixel *pixels = malloc(width * height * sizeof(Pixel));
  if (pixels == NULL) {
    printf("Error: could not allocate memory for pixels\n");
    fclose(image);
    return 1;
  }

  // Read the pixel data from the image file
  fread(pixels, width * height * sizeof(Pixel), 1, image);
  fclose(image);

  // Convert the image to ASCII art
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      // Get the pixel color
      Pixel pixel = pixels[i * width + j];
      int color = (pixel.red + pixel.green + pixel.blue) / 3;

      // Print the ASCII character for the pixel
      char c;
      if (color < 32) {
        c = '@';
      } else if (color < 64) {
        c = '%';
      } else if (color < 96) {
        c = '#';
      } else if (color < 128) {
        c = '+';
      } else if (color < 160) {
        c = '=';
      } else if (color < 192) {
        c = '-';
      } else if (color < 224) {
        c = ':';
      } else {
        c = ' ';
      }

      printf("%c", c);
    }

    printf("\n");
  }

  // Free the memory allocated for the pixel data
  free(pixels);

  return 0;
}