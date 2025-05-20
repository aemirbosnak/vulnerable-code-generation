//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the ASCII character set
char *ASCII_CHARSET = " .:-=+*#%@";

// Load an image from a file
unsigned char *load_image(const char *filename, int *width, int *height) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    return NULL;
  }

  // Read the image header
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, file);

  // Get the image width and height
  *width = header[18] + (header[19] << 8);
  *height = header[22] + (header[23] << 8);

  // Allocate memory for the image data
  unsigned char *data = (unsigned char *)malloc(*width * *height * 3);
  if (data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    return NULL;
  }

  // Read the image data
  fread(data, sizeof(unsigned char), *width * *height * 3, file);

  // Close the file
  fclose(file);

  return data;
}

// Convert an image to ASCII art
char *image_to_ascii(unsigned char *data, int width, int height) {
  // Allocate memory for the ASCII art
  char *ascii = (char *)malloc(width * height + 1);
  if (ascii == NULL) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    return NULL;
  }

  // Convert each pixel to an ASCII character
  for (int i = 0; i < width * height; i++) {
    // Get the average pixel value
    unsigned char average = (data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2]) / 3;

    // Get the corresponding ASCII character
    int index = (int)round((double)average / 255.0 * (strlen(ASCII_CHARSET) - 1));
    ascii[i] = ASCII_CHARSET[index];
  }

  // Add a newline character at the end of the ASCII art
  ascii[width * height] = '\0';

  return ascii;
}

// Save the ASCII art to a file
void save_ascii(const char *filename, char *ascii, int width, int height) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    return;
  }

  // Write the ASCII art to the file
  fprintf(file, "%s", ascii);

  // Close the file
  fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <input image> <output ASCII art>\n", argv[0]);
    return 1;
  }

  // Load the image
  int width, height;
  unsigned char *data = load_image(argv[1], &width, &height);
  if (data == NULL) {
    return 1;
  }

  // Convert the image to ASCII art
  char *ascii = image_to_ascii(data, width, height);
  if (ascii == NULL) {
    return 1;
  }

  // Save the ASCII art to a file
  save_ascii(argv[2], ascii, width, height);

  // Free the memory
  free(data);
  free(ascii);

  return 0;
}