//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the number of gray levels
#define NUM_GRAY_LEVELS 256

// Define the ASCII characters used to represent the gray levels
char *ascii_chars = "@%#*+=-:. ";

// Define the function to convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  // Read the image header
  int width, height;
  if (fscanf(fp, "%d %d\n", &width, &height) != 2) {
    fprintf(stderr, "Error reading image header\n");
    exit(1);
  }

  // Check if the image is too large
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    fprintf(stderr, "Error: image is too large\n");
    exit(1);
  }

  // Allocate memory for the image data
  unsigned char *data = (unsigned char *)malloc(width * height);
  if (data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    exit(1);
  }

  // Read the image data
  if (fread(data, sizeof(unsigned char), width * height, fp) != width * height) {
    fprintf(stderr, "Error reading image data\n");
    exit(1);
  }

  // Close the image file
  fclose(fp);

  // Convert the image data to ASCII art
  char *ascii_art = (char *)malloc(width * height);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    exit(1);
  }

  for (int i = 0; i < width * height; i++) {
    // Calculate the gray level of the pixel
    int gray_level = data[i];

    // Convert the gray level to an ASCII character
    ascii_art[i] = ascii_chars[gray_level * NUM_GRAY_LEVELS / 256];
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii_art[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the image data and ASCII art
  free(data);
  free(ascii_art);
}

// Main function
int main(int argc, char **argv) {
  // Check if a filename was specified
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}