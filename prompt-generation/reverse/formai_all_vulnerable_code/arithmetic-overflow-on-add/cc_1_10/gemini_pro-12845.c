//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
char *image_to_ascii(const char *filename) {
  // Open the image file
  FILE *image_file = fopen(filename, "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", filename);
    return NULL;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, image_file);
  fread(&height, sizeof(int), 1, image_file);

  // Create a 2D array to store the pixel values
  unsigned char **pixels = (unsigned char **)malloc(height * sizeof(unsigned char *));
  for (int i = 0; i < height; i++) {
    pixels[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
  }

  // Read the pixel values from the image file
  fread(pixels[0], sizeof(unsigned char), width * height, image_file);

  // Close the image file
  fclose(image_file);

  // Convert the pixel values to ASCII characters
  char *ascii_art = (char *)malloc((width + 1) * height * sizeof(char));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      ascii_art[i * (width + 1) + j] = " .,-~:;=!*#$@"[pixels[i][j] / 26];
    }
    ascii_art[i * (width + 1) + width] = '\n';
  }

  // Free the memory allocated for the pixel values
  for (int i = 0; i < height; i++) {
    free(pixels[i]);
  }
  free(pixels);

  // Return the ASCII art
  return ascii_art;
}

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
  // Get the length of the ASCII art
  int length = strlen(ascii_art);

  // Print the ASCII art
  for (int i = 0; i < length; i++) {
    putchar(ascii_art[i]);
  }
}

// Function to free the memory allocated for the ASCII art
void free_ascii_art(char *ascii_art) {
  // Free the memory
  free(ascii_art);
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided an image file
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  char *ascii_art = image_to_ascii(argv[1]);
  if (ascii_art == NULL) {
    return 1;
  }

  // Print the ASCII art
  print_ascii_art(ascii_art);

  // Free the memory allocated for the ASCII art
  free_ascii_art(ascii_art);

  return 0;
}