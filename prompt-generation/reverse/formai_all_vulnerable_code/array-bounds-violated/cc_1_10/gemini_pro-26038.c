//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the number of gray levels
#define GRAY_LEVELS 256

// Define the character used to represent each gray level
char gray_chars[] = " .:-=+*#%@";

// Read the image from a file
void read_image(char *filename, int *width, int *height, unsigned char *data) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    exit(1);
  }

  // Read the header information
  fread(width, sizeof(int), 1, fp);
  fread(height, sizeof(int), 1, fp);

  // Read the image data
  fread(data, sizeof(unsigned char), *width * *height, fp);

  fclose(fp);
}

// Convert the image to ASCII art
void convert_to_ascii(int width, int height, unsigned char *data) {
  int i, j;
  char ascii_art[MAX_WIDTH * MAX_HEIGHT];

  // Calculate the average gray level for each pixel
  for (i = 0; i < width * height; i++) {
    ascii_art[i] = gray_chars[data[i] / (GRAY_LEVELS / sizeof(gray_chars))];
  }

  // Print the ASCII art to the console
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("%c", ascii_art[i * width + j]);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  int width, height;
  unsigned char data[MAX_WIDTH * MAX_HEIGHT];

  // Check if the user specified an input file
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    exit(1);
  }

  // Read the image from the file
  read_image(argv[1], &width, &height, data);

  // Convert the image to ASCII art
  convert_to_ascii(width, height, data);

  return 0;
}