//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
/*
 * Image to ASCII art converter
 *
 * Usage: ./asciiart [image_file]
 *
 * Example: ./asciiart myimage.jpg
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 1080
#define MAX_WIDTH 1920
#define ASCII_CHARS " .,:;iIHMl$%#@*+-=?&"

int main(int argc, char *argv[]) {
  // Check command-line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s [image_file]\n", argv[0]);
    return 1;
  }

  // Open image file
  FILE *fp = fopen(argv[1], "rb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    return 1;
  }

  // Read image dimensions
  int width, height, channels;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);
  fread(&channels, sizeof(int), 1, fp);

  // Check image dimensions
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    fprintf(stderr, "Image dimensions too large\n");
    fclose(fp);
    return 1;
  }

  // Allocate memory for image data
  unsigned char *image = malloc(width * height * channels);
  if (!image) {
    fprintf(stderr, "Error allocating memory\n");
    fclose(fp);
    return 1;
  }

  // Read image data
  fread(image, sizeof(unsigned char), width * height * channels, fp);

  // Close image file
  fclose(fp);

  // Convert image to ASCII art
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = (y * width + x) * channels;
      int value = image[index];
      int char_index = (value * strlen(ASCII_CHARS)) / 256;
      printf("%c", ASCII_CHARS[char_index]);
    }
    printf("\n");
  }

  // Free memory
  free(image);

  return 0;
}