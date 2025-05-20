//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
    return 1;
  }

  // Read the image file into memory.
  FILE *f = fopen(argv[1], "rb");
  if (f == NULL) {
    perror("fopen");
    return 1;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  unsigned char *data = malloc(fsize);
  if (data == NULL) {
    perror("malloc");
    return 1;
  }
  fread(data, 1, fsize, f);
  fclose(f);

  // Parse the image header.
  int width, height;
  if (data[0] == 'B' && data[1] == 'M') {
    width = *(int *)(data + 18);
    height = *(int *)(data + 22);
  } else {
    fprintf(stderr, "Invalid image format\n");
    return 1;
  }

  // Convert the image data to ASCII art.
  char *ascii = malloc(width * height);
  if (ascii == NULL) {
    perror("malloc");
    return 1;
  }
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int offset = (y * width + x) * 3;
      int r = data[offset + 2];
      int g = data[offset + 1];
      int b = data[offset];
      int gray = (r + g + b) / 3;
      ascii[y * width + x] = " .:-=+*#%@"[gray / 25];
    }
  }

  // Print the ASCII art to the console.
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", ascii[y * width + x]);
    }
    printf("\n");
  }

  // Free the allocated memory.
  free(data);
  free(ascii);

  return 0;
}