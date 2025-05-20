//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main() {
  // Read the image from a file.
  FILE *image_file = fopen("image.ppm", "r");
  if (image_file == NULL) {
    perror("Error opening image file");
    return EXIT_FAILURE;
  }

  // Read the header information from the image file.
  char header[100];
  fscanf(image_file, "%s", header);
  if (strcmp(header, "P3") != 0) {
    fprintf(stderr, "Error: Image file is not in PPM format\n");
    fclose(image_file);
    return EXIT_FAILURE;
  }

  int width, height, max_value;
  fscanf(image_file, "%d %d %d", &width, &height, &max_value);

  // Allocate memory for the image data.
  unsigned char *image_data = (unsigned char *)malloc(width * height * 3);
  if (image_data == NULL) {
    perror("Error allocating memory for image data");
    fclose(image_file);
    return EXIT_FAILURE;
  }

  // Read the image data from the file.
  fread(image_data, 1, width * height * 3, image_file);
  fclose(image_file);

  // Convert the image data to ASCII art.
  char *ascii_art = (char *)malloc(width * height);
  if (ascii_art == NULL) {
    perror("Error allocating memory for ASCII art");
    free(image_data);
    return EXIT_FAILURE;
  }

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the average color value for the pixel.
      int r = image_data[(y * width + x) * 3];
      int g = image_data[(y * width + x) * 3 + 1];
      int b = image_data[(y * width + x) * 3 + 2];
      int average_color = (r + g + b) / 3;

      // Convert the average color value to an ASCII character.
      char ascii_character;
      if (average_color < 64) {
        ascii_character = '#';
      } else if (average_color < 128) {
        ascii_character = '@';
      } else if (average_color < 192) {
        ascii_character = ':';
      } else {
        ascii_character = ' ';
      }

      // Append the ASCII character to the ASCII art string.
      ascii_art[y * width + x] = ascii_character;
    }
  }

  // Print the ASCII art to the console.
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", ascii_art[y * width + x]);
    }
    printf("\n");
  }

  // Free the memory allocated for the image data and the ASCII art.
  free(image_data);
  free(ascii_art);

  return EXIT_SUCCESS;
}