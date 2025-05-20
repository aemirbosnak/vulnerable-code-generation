//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the number of ASCII characters to use
#define NUM_CHARS 70

// Define the ASCII characters to use
char chars[] = " .,-~:;=!*#$@";

// Define the function to convert an image to ASCII art
void image_to_ascii(const char *filename) {
  // Open the image file
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(1);
  }

  // Read the image header
  unsigned char header[54];
  fread(header, 1, 54, file);

  // Get the image width and height
  int width = header[18] + (header[19] << 8);
  int height = header[22] + (header[23] << 8);

  // Allocate memory for the image data
  unsigned char *data = malloc(width * height * 3);

  // Read the image data
  fread(data, 1, width * height * 3, file);

  // Close the image file
  fclose(file);

  // Convert the image data to ASCII art
  char *ascii_art = malloc(width * height);
  for (int i = 0; i < width * height; i++) {
    // Get the average color of the pixel
    unsigned char r = data[i * 3];
    unsigned char g = data[i * 3 + 1];
    unsigned char b = data[i * 3 + 2];
    float avg = (r + g + b) / 3.0f;

    // Map the average color to an ASCII character
    int index = (int)round(avg / 255.0f * (NUM_CHARS - 1));
    ascii_art[i] = chars[index];
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

// Define the main function
int main(int argc, char **argv) {
  // Check if the user specified an image file
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  // Convert the image file to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}