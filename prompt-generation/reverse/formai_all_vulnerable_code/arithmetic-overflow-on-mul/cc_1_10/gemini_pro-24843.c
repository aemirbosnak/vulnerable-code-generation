//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

// Define the number of ASCII characters to use
#define NUM_CHARS 70

// Define the ASCII characters to use
char *chars = " .,-~:;=!*#$@";

// Define the function to convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  // Read the image header
  unsigned char header[54];
  fread(header, sizeof(header), 1, fp);

  // Check if the image is a valid BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: Invalid BMP file\n");
    exit(1);
  }

  // Get the image width and height
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Check if the image is too large
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    fprintf(stderr, "Error: Image is too large\n");
    exit(1);
  }

  // Read the image data
  unsigned char *data = malloc(width * height * 3);
  fread(data, width * height * 3, 1, fp);

  // Close the image file
  fclose(fp);

  // Convert the image data to ASCII art
  char *ascii_art = malloc(width * height);
  for (int i = 0; i < width * height; i++) {
    // Get the average color of the pixel
    unsigned char r = data[i * 3];
    unsigned char g = data[i * 3 + 1];
    unsigned char b = data[i * 3 + 2];
    float avg = (r + g + b) / 3.0;

    // Get the corresponding ASCII character
    int index = (int)(avg / 255.0 * (NUM_CHARS - 1));
    ascii_art[i] = chars[index];
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii_art[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the ASCII art
  free(ascii_art);
  free(data);
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user specified an image file
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(1);
  }

  // Convert the image file to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}