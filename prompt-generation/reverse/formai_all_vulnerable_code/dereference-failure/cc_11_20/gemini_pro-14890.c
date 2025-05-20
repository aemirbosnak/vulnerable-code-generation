//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
  // Allocate memory for the image data
  unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);

  // Load the image data from a file
  FILE *fp = fopen("image.jpg", "rb");
  if (!fp) {
    perror("Error opening image file");
    return EXIT_FAILURE;
  }
  fread(image, 1, WIDTH * HEIGHT * 3, fp);
  fclose(fp);

  // Convert the image data to ASCII art
  char *asciiArt = (char *)malloc(WIDTH * HEIGHT);
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    // Calculate the average color of the pixel
    int r = image[3 * i];
    int g = image[3 * i + 1];
    int b = image[3 * i + 2];
    int avg = (r + g + b) / 3;

    // Convert the average color to an ASCII character
    char c;
    if (avg < 32) {
      c = ' ';
    } else if (avg < 64) {
      c = '.';
    } else if (avg < 96) {
      c = ',';
    } else if (avg < 128) {
      c = '-';
    } else if (avg < 160) {
      c = '=';
    } else if (avg < 192) {
      c = '+';
    } else if (avg < 224) {
      c = '*';
    } else {
      c = '#';
    }

    // Store the ASCII character in the output array
    asciiArt[i] = c;
  }

  // Print the ASCII art to the console
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", asciiArt[i * WIDTH + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the image data and the ASCII art
  free(image);
  free(asciiArt);

  return EXIT_SUCCESS;
}