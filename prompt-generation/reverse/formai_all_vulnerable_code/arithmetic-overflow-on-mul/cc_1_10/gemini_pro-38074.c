//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

// ASCII characters used for the conversion
char *chars = " .,-~:;=!*#$@";

// Function to convert an image to ASCII art
void image_to_ascii(char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  // Read the image header
  unsigned char header[14];
  fread(header, 1, 14, fp);

  // Check if the file is a BMP image
  if (header[0] != 'B' || header[1] != 'M') {
    printf("Error: file is not a BMP image\n");
    fclose(fp);
    return;
  }

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Read the image data
  unsigned char *data = malloc(width * height * 3);
  fread(data, 1, width * height * 3, fp);

  // Close the image file
  fclose(fp);

  // Convert the image to ASCII art
  char *ascii = malloc(WIDTH * HEIGHT);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Calculate the average color of the pixel
      int r = 0, g = 0, b = 0;
      for (int i = 0; i < 3; i++) {
        int offset = (y * WIDTH + x) * 3 + i;
        r += data[offset];
        g += data[offset + 1];
        b += data[offset + 2];
      }
      int avg = (r + g + b) / 3;

      // Convert the average color to an ASCII character
      int index = (int)(avg / 256.0 * (strlen(chars) - 1));
      ascii[y * WIDTH + x] = chars[index];
    }
  }

  // Print the ASCII art
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", ascii[y * WIDTH + x]);
    }
    printf("\n");
  }

  // Free the memory
  free(ascii);
  free(data);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  image_to_ascii(argv[1]);

  return 0;
}