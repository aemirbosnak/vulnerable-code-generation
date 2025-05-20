//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the ASCII character set
char *ascii_chars = " .:░▒▓█";

// Function to convert an image to ASCII art
char *image_to_ascii(unsigned char *image, int width, int height) {
  // Allocate memory for the ASCII art
  char *ascii_art = malloc(width * height * sizeof(char));

  // Convert each pixel to an ASCII character
  for (int i = 0; i < width * height; i++) {
    // Calculate the brightness of the pixel
    int brightness = image[i];

    // Convert the brightness to an ASCII character
    ascii_art[i] = ascii_chars[brightness / 64];
  }

  // Return the ASCII art
  return ascii_art;
}

// Function to print the ASCII art
void print_ascii_art(char *ascii_art, int width, int height) {
  // Print each line of the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Print the ASCII character
      printf("%c", ascii_art[i * width + j]);
    }

    // Print a newline character
    printf("\n");
  }
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided an image file
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Open the image file
  FILE *image_file = fopen(argv[1], "rb");
  if (image_file == NULL) {
    printf("Error: could not open image file\n");
    return 1;
  }

  // Read the image header
  unsigned char header[14];
  fread(header, 14, 1, image_file);

  // Check if the image is a valid BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    printf("Error: invalid BMP file\n");
    return 1;
  }

  // Get the image width and height
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Check if the image is too large
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Error: image is too large\n");
    return 1;
  }

  // Allocate memory for the image data
  unsigned char *image = malloc(width * height * sizeof(unsigned char));

  // Read the image data
  fread(image, width * height, 1, image_file);

  // Close the image file
  fclose(image_file);

  // Convert the image to ASCII art
  char *ascii_art = image_to_ascii(image, width, height);

  // Print the ASCII art
  print_ascii_art(ascii_art, width, height);

  // Free the memory allocated for the ASCII art
  free(ascii_art);

  // Free the memory allocated for the image data
  free(image);

  // Return 0 to indicate success
  return 0;
}