//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 64
#define HEIGHT 64

int main() {
  // Read the image data from a file
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error: could not open image file\n");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, image_file);
  fread(&height, sizeof(int), 1, image_file);

  // Allocate memory for the image data
  unsigned char *image_data = malloc(width * height * 3);
  if (image_data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image data\n");
    return 1;
  }

  // Read the image data
  fread(image_data, 1, width * height * 3, image_file);
  fclose(image_file);

  // Convert the image data to ASCII art
  char *ascii_art = malloc(WIDTH * HEIGHT);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
    return 1;
  }

  double scale_x = (double)width / WIDTH;
  double scale_y = (double)height / HEIGHT;

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int r = image_data[3 * (int)(y * scale_y) * width + 3 * (int)(x * scale_x)];
      int g = image_data[3 * (int)(y * scale_y) * width + 3 * (int)(x * scale_x) + 1];
      int b = image_data[3 * (int)(y * scale_y) * width + 3 * (int)(x * scale_x) + 2];

      double gray = 0.299 * r + 0.587 * g + 0.114 * b;

      char c;
      if (gray < 32) {
        c = '#';
      } else if (gray < 64) {
        c = '&';
      } else if (gray < 96) {
        c = '@';
      } else if (gray < 128) {
        c = ':';
      } else if (gray < 160) {
        c = ',';
      } else if (gray < 192) {
        c = '.';
      } else {
        c = ' ';
      }

      ascii_art[y * WIDTH + x] = c;
    }
  }

  // Print the ASCII art to the console
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", ascii_art[y * WIDTH + x]);
    }
    printf("\n");
  }

  // Free the memory allocated for the image data and ASCII art
  free(image_data);
  free(ascii_art);

  return 0;
}