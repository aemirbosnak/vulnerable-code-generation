//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Convert an image to ASCII art
void image_to_ascii(const char *filename) {
  // Read the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    return;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Create an array to store the image data
  unsigned char *data = (unsigned char *)malloc(width * height);
  if (data == NULL) {
    perror("malloc");
    fclose(fp);
    return;
  }

  // Read the image data
  fread(data, sizeof(unsigned char), width * height, fp);
  fclose(fp);

  // Convert the image data to ASCII art
  char *ascii = (char *)malloc(width * height + 1);
  if (ascii == NULL) {
    perror("malloc");
    free(data);
    return;
  }

  for (int i = 0; i < width * height; i++) {
    // Get the brightness of the pixel
    int brightness = data[i];

    // Convert the brightness to an ASCII character
    char c;
    if (brightness < 32) {
      c = ' ';
    } else if (brightness < 64) {
      c = ',';
    } else if (brightness < 96) {
      c = ':';
    } else if (brightness < 128) {
      c = '=';
    } else if (brightness < 160) {
      c = '+';
    } else if (brightness < 192) {
      c = '*';
    } else if (brightness < 224) {
      c = '%';
    } else {
      c = '#';
    }

    // Add the character to the ASCII string
    ascii[i] = c;
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory
  free(ascii);
  free(data);
}

// Main function
int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  image_to_ascii(argv[1]);

  return 0;
}