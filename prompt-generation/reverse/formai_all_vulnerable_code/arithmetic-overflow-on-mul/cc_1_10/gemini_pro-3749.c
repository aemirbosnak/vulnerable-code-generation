//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert an image to ASCII art
void imageToASCII(char *filename) {
  // Open the image file
  FILE *image = fopen(filename, "rb");
  if (image == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, image);
  fread(&height, sizeof(int), 1, image);

  // Create a 2D array to store the pixel data
  unsigned char **pixels = (unsigned char **)malloc(height * sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    pixels[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
  }

  // Read the pixel data from the file
  fread(pixels, sizeof(unsigned char), width * height, image);

  // Close the image file
  fclose(image);

  // Convert the pixel data to ASCII art
  char **asciiArt = (char **)malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    asciiArt[i] = (char *)malloc(width * sizeof(char));
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Get the pixel value
      unsigned char pixel = pixels[i][j];

      // Convert the pixel value to an ASCII character
      char character;
      if (pixel < 32) {
        character = ' ';
      } else if (pixel < 64) {
        character = '.';
      } else if (pixel < 96) {
        character = ':';
      } else if (pixel < 128) {
        character = '=';
      } else if (pixel < 160) {
        character = '+';
      } else if (pixel < 192) {
        character = '*';
      } else if (pixel < 224) {
        character = '#';
      } else {
        character = '@';
      }

      // Store the ASCII character in the 2D array
      asciiArt[i][j] = character;
    }
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", asciiArt[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the 2D arrays
  for (int i = 0; i < height; i++) {
    free(pixels[i]);
    free(asciiArt[i]);
  }
  free(pixels);
  free(asciiArt);
}

// Main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  imageToASCII(argv[1]);

  return 0;
}