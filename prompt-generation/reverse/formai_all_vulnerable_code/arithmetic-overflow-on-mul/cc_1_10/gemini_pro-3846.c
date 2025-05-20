//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the ASCII characters to be used for the conversion.
char *asciiChars = " .,-~:;=!*#$@";

// Convert an image to ASCII art.
void imageToAscii(char *filename) {
  // Open the image file.
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the image header.
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Read the image data.
  unsigned char *data = malloc(width * height);
  fread(data, sizeof(unsigned char), width * height, fp);

  // Close the image file.
  fclose(fp);

  // Convert the image data to ASCII art.
  char *asciiArt = malloc(width * height + 1);
  for (int i = 0; i < width * height; i++) {
    // Calculate the ASCII character to be used for the pixel.
    int index = (int) (data[i] * strlen(asciiChars) / 255.0);
    asciiArt[i] = asciiChars[index];
  }

  // Print the ASCII art to the console.
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", asciiArt[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the ASCII art.
  free(asciiArt);
  free(data);
}

// Main function.
int main(int argc, char **argv) {
  // Check if the user has specified an image file.
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  // Convert the image file to ASCII art.
  imageToAscii(argv[1]);

  return 0;
}