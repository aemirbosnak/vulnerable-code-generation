//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH  80
#define MAX_HEIGHT 25

char *ascii_chars = " .,-~:;=@#*%8";

void convert_image(char *image, int width, int height) {
  int x, y, i, j, p;
  float brightness;
  char c;

  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      p = y * width + x;
      brightness = (float)image[p] / 255.0f;
      i = (int)(brightness * (strlen(ascii_chars) - 1));
      c = ascii_chars[i];
      printf("%c", c);
    }
    printf("\n");
  }
}

int main(void) {
  char *image;
  int width, height;

  // Read image from file
  FILE *fp = fopen("image.txt", "rb");
  if (fp == NULL) {
    printf("Error: could not open image file\n");
    return 1;
  }
  fscanf(fp, "%d %d", &width, &height);
  image = malloc(width * height);
  fread(image, 1, width * height, fp);
  fclose(fp);

  // Convert image to ASCII art
  convert_image(image, width, height);

  // Free memory
  free(image);

  return 0;
}