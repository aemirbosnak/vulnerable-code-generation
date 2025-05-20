//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the ASCII characters to use for the conversion.
char *ascii_chars = " .,-:;=!*#%@";

// Convert an image to ASCII art.
void image_to_ascii(const char *filename) {
  // Read the image file.
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    return;
  }

  // Get the image dimensions.
  int width, height;
  fscanf(fp, "%d %d", &width, &height);

  // Read the image data.
  unsigned char *data = malloc(width * height);
  fread(data, sizeof(unsigned char), width * height, fp);
  fclose(fp);

  // Convert the image data to ASCII art.
  char *ascii_art = malloc(width * height);
  for (int i = 0; i < width * height; i++) {
    // Get the brightness of the pixel.
    int brightness = data[i];

    // Find the ASCII character that corresponds to the brightness.
    int index = (int) round((double) brightness / 255 * (strlen(ascii_chars) - 1));
    ascii_art[i] = ascii_chars[index];
  }

  // Print the ASCII art.
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii_art[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the ASCII art.
  free(ascii_art);
}

int main(int argc, char **argv) {
  // Check the number of arguments.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art.
  image_to_ascii(argv[1]);

  return 0;
}