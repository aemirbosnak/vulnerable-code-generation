//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

// Define the number of ASCII characters to use
#define NUM_ASCII_CHARS 70

// Define the ASCII characters to use
char *ascii_chars = " .:-=+*#%@";

// Convert an image to ASCII art
void image_to_ascii(char *image_file, char *output_file) {
  // Open the image file
  FILE *image = fopen(image_file, "rb");
  if (image == NULL) {
    printf("Error opening image file: %s\n", image_file);
    return;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, image);
  fread(&height, sizeof(int), 1, image);

  // Create an array to store the image data
  unsigned char *data = malloc(width * height * 3);
  fread(data, sizeof(unsigned char), width * height * 3, image);
  fclose(image);

  // Create an array to store the ASCII art
  char *ascii_art = malloc(width * height + 1);
  memset(ascii_art, ' ', width * height);
  ascii_art[width * height] = '\0';

  // Convert each pixel to an ASCII character
  for (int i = 0; i < width * height; i++) {
    // Get the average of the RGB values
    int avg = (data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2]) / 3;

    // Find the closest ASCII character
    int index = round(avg / 255.0 * (NUM_ASCII_CHARS - 1));
    ascii_art[i] = ascii_chars[index];
  }

  // Open the output file
  FILE *output = fopen(output_file, "w");
  if (output == NULL) {
    printf("Error opening output file: %s\n", output_file);
    return;
  }

  // Write the ASCII art to the output file
  fprintf(output, "%s", ascii_art);
  fclose(output);

  // Free the memory
  free(data);
  free(ascii_art);
}

// Main function
int main(int argc, char **argv) {
  // Check the number of arguments
  if (argc != 3) {
    printf("Usage: %s <image_file> <output_file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1], argv[2]);

  return 0;
}