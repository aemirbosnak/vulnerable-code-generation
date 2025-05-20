//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

int main() {
  // Read the image from a file
  FILE *image_file = fopen("image.jpg", "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening the image file.\n");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, image_file);
  fread(&height, sizeof(int), 1, image_file);

  // Create an array to store the pixel data
  unsigned char *pixels = malloc(width * height * 3);
  if (pixels == NULL) {
    fprintf(stderr, "Error allocating memory for the pixel data.\n");
    fclose(image_file);
    return 1;
  }

  // Read the pixel data from the file
  fread(pixels, 1, width * height * 3, image_file);
  fclose(image_file);

  // Convert the image to ASCII art
  char *ascii_art = malloc(WIDTH * HEIGHT);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error allocating memory for the ASCII art.\n");
    free(pixels);
    return 1;
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      // Get the average pixel value for the current cell
      int pixel_value = 0;
      for (int k = 0; k < 3; k++) {
        int pixel_index = (i * width + j) * 3 + k;
        pixel_value += pixels[pixel_index];
      }
      pixel_value /= 3;

      // Convert the pixel value to an ASCII character
      char c;
      if (pixel_value < 32) {
        c = '@';
      } else if (pixel_value < 64) {
        c = '%';
      } else if (pixel_value < 96) {
        c = '*';
      } else if (pixel_value < 128) {
        c = '=';
      } else if (pixel_value < 160) {
        c = '+';
      } else if (pixel_value < 192) {
        c = '-';
      } else if (pixel_value < 224) {
        c = ':';
      } else {
        c = ' ';
      }

      // Store the ASCII character in the output array
      ascii_art[i * WIDTH + j] = c;
    }
  }

  // Print the ASCII art to the console
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", ascii_art[i * WIDTH + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the pixel data and the ASCII art
  free(pixels);
  free(ascii_art);

  return 0;
}