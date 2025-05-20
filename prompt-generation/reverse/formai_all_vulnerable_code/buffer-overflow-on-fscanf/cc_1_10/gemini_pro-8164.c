//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert an image to ASCII art
char *image_to_ascii(const char *filename) {
  // Open the image file
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  // Get the image dimensions
  int width, height;
  fscanf(fp, "%d %d", &width, &height);

  // Read the image data
  unsigned char *data = malloc(width * height);
  fread(data, 1, width * height, fp);
  fclose(fp);

  // Convert the image data to ASCII art
  char *ascii = malloc(width * height + 1);
  for (int i = 0; i < width * height; i++) {
    ascii[i] = ".,:;i!1zt*#9876543210?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
        [data[i] * 64 / 256];
  }
  ascii[width * height] = '\0';

  // Return the ASCII art
  return ascii;
}

// Print the ASCII art to the console
void print_ascii(char *ascii, int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii[i * width + j]);
    }
    printf("\n");
  }
}

// Main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Convert the image to ASCII art
  char *ascii = image_to_ascii(argv[1]);
  if (ascii == NULL) {
    printf("Error opening image file\n");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  sscanf(ascii, "%d %d", &width, &height);

  // Print the ASCII art to the console
  print_ascii(ascii, width, height);

  // Free the ASCII art
  free(ascii);

  return 0;
}