//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <image>\n", argv[0]);
    exit(1);
  }

  char *filename = argv[1];

  FILE *file = fopen(filename, "rb");
  if (!file) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  int width, height;
  unsigned char data[MAX_WIDTH * MAX_HEIGHT];

  // Read image header
  fseek(file, 18, SEEK_SET);
  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);

  // Read image data
  fseek(file, 54, SEEK_SET);
  fread(data, sizeof(unsigned char), width * height, file);
  fclose(file);

  // Convert image data to ASCII art
  char ascii[MAX_HEIGHT][MAX_WIDTH];
  memset(ascii, ' ', MAX_WIDTH * MAX_HEIGHT);

  const char *ascii_chars = "@%#*+=-:. ";
  const int num_chars = strlen(ascii_chars);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      unsigned char value = data[i * width + j];

      int index = value * num_chars / 256;
      ascii[i][j] = ascii_chars[index];
    }
  }

  // Print ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      putchar(ascii[i][j]);
    }
    putchar('\n');
  }

  return 0;
}