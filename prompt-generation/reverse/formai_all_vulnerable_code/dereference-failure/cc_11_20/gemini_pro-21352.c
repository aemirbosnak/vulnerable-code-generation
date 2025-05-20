//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
  // Open the image file
  FILE *fp = fopen("image.jpg", "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the image data into a buffer
  unsigned char *buffer = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
  if (buffer == NULL) {
    perror("Error allocating memory");
    return EXIT_FAILURE;
  }
  fread(buffer, 1, WIDTH * HEIGHT * 3, fp);
  fclose(fp);

  // Convert the image data to ASCII art
  char *asciiArt = (char *)malloc(WIDTH * HEIGHT + 1);
  if (asciiArt == NULL) {
    perror("Error allocating memory");
    return EXIT_FAILURE;
  }
  int i, j, k;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      int index = i * WIDTH * 3 + j * 3;
      int r = buffer[index];
      int g = buffer[index + 1];
      int b = buffer[index + 2];
      int brightness = (r + g + b) / 3;
      char c;
      if (brightness < 32) {
        c = '@';
      } else if (brightness < 64) {
        c = '%';
      } else if (brightness < 96) {
        c = '#';
      } else if (brightness < 128) {
        c = '*';
      } else if (brightness < 160) {
        c = '+';
      } else if (brightness < 192) {
        c = ':';
      } else if (brightness < 224) {
        c = ',';
      } else {
        c = ' ';
      }
      asciiArt[i * WIDTH + j] = c;
    }
    asciiArt[i * WIDTH + j] = '\n';
  }
  asciiArt[WIDTH * HEIGHT] = '\0';

  // Print the ASCII art to the console
  printf("%s", asciiArt);

  // Free the allocated memory
  free(buffer);
  free(asciiArt);

  return EXIT_SUCCESS;
}