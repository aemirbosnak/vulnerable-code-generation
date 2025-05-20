//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the ASCII characters used for the conversion
const char *asciiChars = " .-:=+*#%@";

// Convert an image to ASCII art
void imageToAscii(unsigned char *imageData, int width, int height) {
  // Create an array to store the ASCII art
  char *asciiArt = malloc(width * height + 1);

  // Convert each pixel to an ASCII character
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Get the brightness of the pixel
      int brightness = imageData[y * width + x];

      // Map the brightness to an ASCII character
      int charIndex = (int) (brightness / 255.0 * (strlen(asciiChars) - 1));

      // Store the ASCII character in the array
      asciiArt[y * width + x] = asciiChars[charIndex];
    }
  }

  // Add a newline character to the end of the array
  asciiArt[width * height] = '\n';

  // Print the ASCII art to the console
  printf("%s", asciiArt);

  // Free the memory allocated for the ASCII art
  free(asciiArt);
}

// Load an image from a file
unsigned char *loadImage(const char *filename, int *width, int *height) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the header information
  unsigned char header[18];
  fread(header, 1, 18, file);

  // Check if the file is a BMP image
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: File is not a BMP image\n");
    fclose(file);
    return NULL;
  }

  // Extract the width and height of the image
  *width = *(int *) &header[18];
  *height = *(int *) &header[22];

  // Read the image data
  unsigned char *imageData = malloc(*width * *height);
  fread(imageData, 1, *width * *height, file);

  // Close the file
  fclose(file);

  // Return the image data
  return imageData;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was specified
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Load the image from the file
  int width, height;
  unsigned char *imageData = loadImage(argv[1], &width, &height);
  if (imageData == NULL) {
    return 1;
  }

  // Convert the image to ASCII art
  imageToAscii(imageData, width, height);

  // Free the memory allocated for the image data
  free(imageData);

  return 0;
}