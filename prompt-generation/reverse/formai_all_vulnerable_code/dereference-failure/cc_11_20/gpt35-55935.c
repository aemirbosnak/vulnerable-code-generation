//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 120
#define MAX_HEIGHT 40
#define MAX_PIXELS MAX_WIDTH * MAX_HEIGHT

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Open input file
  FILE *infile = fopen(argv[1], "r");
  if (!infile) {
    printf("Error: Could not open file %s\n", argv[1]);
    return 1;
  }

  // Read image header
  char format[3];
  int width, height, maxval;
  fscanf(infile, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval);

  // Check image format
  if (strcmp(format, "P3")) {
    printf("Error: Only P3 format is supported\n");
    return 1;
  }

  // Check image dimensions
  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Error: Image is too large\n");
    return 1;
  }

  // Read image pixels
  int pixels[MAX_PIXELS];
  int i = 0;
  while (!feof(infile) && i < MAX_PIXELS) {
    int r, g, b;
    fscanf(infile, "%d %d %d", &r, &g, &b);
    pixels[i] = 0.3 * r + 0.59 * g + 0.11 * b; // Convert to grayscale
    i++;
  }
  fclose(infile);

  // Print ASCII art
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int pixel = pixels[y * width + x];
      char ascii;
      if (pixel < 30) ascii = ' ';
      else if (pixel < 60) ascii = '.';
      else if (pixel < 90) ascii = '*';
      else if (pixel < 120) ascii = ':';
      else if (pixel < 150) ascii = 'o';
      else if (pixel < 180) ascii = '&';
      else if (pixel < 210) ascii = '8';
      else if (pixel < 240) ascii = '#';
      else ascii = '@';
      putchar(ascii);
    }
    putchar('\n');
  }

  return 0;
}