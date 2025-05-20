//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  fseek(fp, 10, SEEK_SET);
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    fprintf(stderr, "Image too large. Max size: %dx%d\n", MAX_WIDTH, MAX_HEIGHT);
    return 1;
  }

  unsigned char *pixels = malloc(width * height * 3);
  if (pixels == NULL) {
    perror("malloc");
    return 1;
  }

  fread(pixels, sizeof(unsigned char), width * height * 3, fp);
  fclose(fp);

  double scale = 255.0 / (MAX_WIDTH * MAX_HEIGHT);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = (y * width + x) * 3;
      double average = (pixels[index] + pixels[index + 1] + pixels[index + 2]) / 3.0;
      char c = (char)(average / scale);
      printf("%c", c);
    }
    printf("\n");
  }

  free(pixels);
  return 0;
}