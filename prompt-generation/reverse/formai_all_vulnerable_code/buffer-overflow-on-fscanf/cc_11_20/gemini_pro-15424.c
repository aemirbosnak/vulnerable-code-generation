//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <image.ppm>\n", argv[0]);
    return 1;
  }

  FILE *image = fopen(argv[1], "rb");
  if (image == NULL) {
    printf("Error: could not open image file.\n");
    return 1;
  }

  // Read the header information from the image file.
  char header[50];
  fscanf(image, "%s\n", header);
  if (strcmp(header, "P3") != 0) {
    printf("Error: image file is not in the PPM format.\n");
    fclose(image);
    return 1;
  }

  int width, height, max_color;
  fscanf(image, "%d %d\n", &width, &height);
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Error: image is too large.\n");
    fclose(image);
    return 1;
  }

  fscanf(image, "%d\n", &max_color);
  if (max_color > 255) {
    printf("Error: image has too many colors.\n");
    fclose(image);
    return 1;
  }

  // Create a 2D array to store the pixel data.
  int pixels[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fscanf(image, "%d", &pixels[i][j]);
    }
  }

  fclose(image);

  // Convert the pixel data to ASCII art.
  char ascii_art[height][width + 1];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Convert the pixel value to a brightness level.
      int brightness = pixels[i][j] / 255;

      // Choose an ASCII character that corresponds to the brightness level.
      char character;
      switch (brightness) {
        case 0:
          character = ' ';
          break;
        case 1:
          character = '.';
          break;
        case 2:
          character = ',';
          break;
        case 3:
          character = ':';
          break;
        case 4:
          character = 'o';
          break;
        case 5:
          character = 'O';
          break;
        case 6:
          character = '#';
          break;
        case 7:
          character = '@';
          break;
        default:
          character = ' ';
          break;
      }

      // Store the ASCII character in the array.
      ascii_art[i][j] = character;
    }

    // Add a newline character to the end of the line.
    ascii_art[i][width] = '\n';
  }

  // Print the ASCII art to the console.
  for (int i = 0; i < height; i++) {
    printf("%s", ascii_art[i]);
  }

  return 0;
}