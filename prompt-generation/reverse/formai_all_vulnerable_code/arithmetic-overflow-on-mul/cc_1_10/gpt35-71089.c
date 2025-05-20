//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80 // Maximum width of the ASCII art

// The ASCII characters used to represent different intensity values
char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};


int main(int argc, char **argv){

  if (argc < 2) {
    printf("Usage: %s image_file\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  FILE *file = fopen(filename, "rb");

  if (!file) {
    printf("Could not open %s\n", filename);
    return 1;
  }

  // Read the header of the BMP file
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, file);

  // Get the width and height of the image
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Calculate the padding needed to ensure each row of the image is a multiple of 4 bytes
  int padding = 0;
  if ((width * 3) % 4 != 0) {
    padding = 4 - (width * 3) % 4;
  }

  // Allocate memory for the image array and read the pixel data
  unsigned char *data = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);
  fread(data, sizeof(unsigned char), width * height * 3, file);
  fclose(file);

  // Convert the image to ASCII art
  printf("\n");

  for (int i = 0; i < height; i++) {

    for (int j = 0; j < width; j++) {

      // Calculate the intensity value of the pixel
      int index = i * width * 3 + j * 3;
      unsigned char r = data[index];
      unsigned char g = data[index + 1];
      unsigned char b = data[index + 2];
      double intensity = (0.2126 * r + 0.7152 * g + 0.0722 * b) / 255;

      // Map the intensity value to an ASCII character
      int ascii_index = (int) (intensity * 10);
      if (ascii_index > 9) {
        ascii_index = 9;
      }

      // Print the ASCII character
      printf("%c", ascii_chars[ascii_index]);

    }

    printf("\n");

    // Skip the padding at the end of each row
    for (int k = 0; k < padding; k++) {
      fgetc(file);
    }

  }

  printf("\n");

  // Free the memory used by the image array
  free(data);

  return 0;
}