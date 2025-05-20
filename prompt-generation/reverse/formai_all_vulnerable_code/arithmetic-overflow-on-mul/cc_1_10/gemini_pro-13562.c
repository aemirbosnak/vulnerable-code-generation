//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

unsigned char image[MAX_HEIGHT][MAX_WIDTH];
int width, height;

void read_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("fopen");
    exit(1);
  }
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);
  fread(image, sizeof(unsigned char), width * height, fp);
  fclose(fp);
}

void write_image(const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    perror("fopen");
    exit(1);
  }
  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);
  fwrite(image, sizeof(unsigned char), width * height, fp);
  fclose(fp);
}

void flip_image() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      unsigned char temp = image[i][j];
      image[i][j] = image[i][width - 1 - j];
      image[i][width - 1 - j] = temp;
    }
  }
}

void adjust_brightness(int delta) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int value = image[i][j] + delta;
      if (value < 0) {
        value = 0;
      } else if (value > 255) {
        value = 255;
      }
      image[i][j] = value;
    }
  }
}

void adjust_contrast(float factor) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int value = image[i][j] * factor;
      if (value < 0) {
        value = 0;
      } else if (value > 255) {
        value = 255;
      }
      image[i][j] = value;
    }
  }
}

int main() {
  read_image("input.bmp");

  flip_image(); // Flips the image horizontally
  adjust_brightness(50); // Increases the brightness by 50
  adjust_contrast(1.5); // Increases the contrast by 1.5

  write_image("output.bmp"); // Writes the modified image to a file

  return 0;
}