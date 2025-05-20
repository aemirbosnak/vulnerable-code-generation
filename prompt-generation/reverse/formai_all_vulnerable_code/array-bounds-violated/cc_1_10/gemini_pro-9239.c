//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters to use for the ASCII art
char *chars = " .:-=+*#%@";

// Read an image from a file
unsigned char *read_image(char *filename, int *width, int *height) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the header of the image
  unsigned char header[14];
  if (fread(header, 1, 14, file) != 14) {
    fprintf(stderr, "Error reading header of file %s\n", filename);
    fclose(file);
    return NULL;
  }

  // Check if the file is a BMP image
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: file %s is not a BMP image\n", filename);
    fclose(file);
    return NULL;
  }

  // Read the width and height of the image
  *width = (int) header[18] + (int) header[19] * 256;
  *height = (int) header[22] + (int) header[23] * 256;

  // Allocate memory for the image data
  unsigned char *data = malloc(*width * *height);
  if (data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    fclose(file);
    return NULL;
  }

  // Read the image data
  if (fread(data, 1, *width * *height, file) != *width * *height) {
    fprintf(stderr, "Error reading image data from file %s\n", filename);
    free(data);
    fclose(file);
    return NULL;
  }

  // Close the file
  fclose(file);

  // Return the image data
  return data;
}

// Convert an image to ASCII art
char *image_to_ascii(unsigned char *data, int width, int height) {
  // Allocate memory for the ASCII art
  char *ascii = malloc(width * height + 1);
  if (ascii == NULL) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    return NULL;
  }

  // Convert each pixel of the image to an ASCII character
  for (int i = 0; i < width * height; i++) {
    // Get the pixel value
    unsigned char pixel = data[i];

    // Convert the pixel value to an ASCII character
    char c = chars[pixel / 32];

    // Add the ASCII character to the ASCII art
    ascii[i] = c;
  }

  // Add a newline character to the end of the ASCII art
  ascii[width * height] = '\n';

  // Return the ASCII art
  return ascii;
}

// Write ASCII art to a file
void write_ascii_to_file(char *ascii, char *filename) {
  // Open the file
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }

  // Write the ASCII art to the file
  fprintf(file, "%s", ascii);

  // Close the file
  fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user specified an input image file
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input image file>\n", argv[0]);
    return 1;
  }

  // Read the input image file
  int width, height;
  unsigned char *data = read_image(argv[1], &width, &height);
  if (data == NULL) {
    return 1;
  }

  // Convert the image to ASCII art
  char *ascii = image_to_ascii(data, width, height);
  if (ascii == NULL) {
    free(data);
    return 1;
  }

  // Write the ASCII art to a file
  write_ascii_to_file(ascii, "output.txt");

  // Free the memory allocated for the image data and the ASCII art
  free(data);
  free(ascii);

  return 0;
}