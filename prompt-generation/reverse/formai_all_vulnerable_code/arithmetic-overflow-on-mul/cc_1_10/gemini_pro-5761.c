//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Function to convert an RGB pixel to a grayscale value
double rgb_to_grayscale(unsigned char r, unsigned char g, unsigned char b) {
  return 0.299 * r + 0.587 * g + 0.114 * b;
}

// Function to convert a grayscale value to an ASCII character
char grayscale_to_ascii(double grayscale) {
  char ascii_character;
  if (grayscale >= 230) {
    ascii_character = ' ';
  } else if (grayscale >= 200) {
    ascii_character = '.';
  } else if (grayscale >= 170) {
    ascii_character = ':';
  } else if (grayscale >= 140) {
    ascii_character = ',';
  } else if (grayscale >= 110) {
    ascii_character = '-';
  } else if (grayscale >= 80) {
    ascii_character = '=';
  } else if (grayscale >= 50) {
    ascii_character = '#';
  } else {
    ascii_character = '@';
  }
  return ascii_character;
}

// Function to convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *image_file = fopen(filename, "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", filename);
    return;
  }

  // Read the image header
  unsigned char header[14];
  fread(header, 1, 14, image_file);

  // Check if the image is a BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: image is not a BMP file\n");
    fclose(image_file);
    return;
  }

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Check if the image is too large
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    fprintf(stderr, "Error: image is too large\n");
    fclose(image_file);
    return;
  }

  // Allocate memory for the image data
  unsigned char *image_data = malloc(width * height * 3);
  if (image_data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    fclose(image_file);
    return;
  }

  // Read the image data
  fread(image_data, 1, width * height * 3, image_file);

  // Close the image file
  fclose(image_file);

  // Convert the image to grayscale
  double *grayscale_data = malloc(width * height);
  if (grayscale_data == NULL) {
    fprintf(stderr, "Error allocating memory for grayscale data\n");
    free(image_data);
    return;
  }
  for (int i = 0; i < width * height; i++) {
    grayscale_data[i] = rgb_to_grayscale(image_data[i * 3], image_data[i * 3 + 1], image_data[i * 3 + 2]);
  }
  free(image_data);

  // Convert the grayscale image to ASCII art
  char *ascii_art = malloc(width * height + 1);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error allocating memory for ASCII art\n");
    free(grayscale_data);
    return;
  }
  for (int i = 0; i < width * height; i++) {
    ascii_art[i] = grayscale_to_ascii(grayscale_data[i]);
  }
  ascii_art[width * height] = '\0';

  // Print the ASCII art to the console
  printf("%s\n", ascii_art);
  
  // Free the memory allocated for the grayscale image and the ASCII art
  free(grayscale_data);
  free(ascii_art);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s image.bmp\n", argv[0]);
    return 1;
  }

  image_to_ascii(argv[1]);

  return 0;
}