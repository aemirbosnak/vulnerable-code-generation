//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to swap two pixel values
void swap(unsigned char *a, unsigned char *b) {
  unsigned char temp = *a;
  *a = *b;
  *b = temp;
}

// Flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      swap(&image[y * width + x], &image[y * width + (width - 1 - x)]);
    }
  }
}

// Flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      swap(&image[(y * width) + x], &image[((height - 1 - y) * width) + x]);
    }
  }
}

// Change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      image[y * width + x] += brightness;
    }
  }
}

// Change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      image[y * width + x] = (image[y * width + x] * contrast) / 100;
    }
  }
}

int main() {
  // Load the image from a file
  FILE *fp = fopen("image.pgm", "rb");
  if (fp == NULL) {
    printf("Error opening image file\n");
    return 1;
  }

  int width, height, max_value;
  fscanf(fp, "P5\n%d %d\n%d\n", &width, &height, &max_value);

  unsigned char *image = malloc(width * height);
  fread(image, width * height, 1, fp);
  fclose(fp);

  // Flip the image horizontally
  flip_horizontal(image, width, height);

  // Change the brightness of the image
  change_brightness(image, width, height, 50);

  // Change the contrast of the image
  change_contrast(image, width, height, 150);

  // Save the modified image to a file
  fp = fopen("modified_image.pgm", "wb");
  if (fp == NULL) {
    printf("Error opening output image file\n");
    return 1;
  }

  fprintf(fp, "P5\n%d %d\n%d\n", width, height, max_value);
  fwrite(image, width * height, 1, fp);
  fclose(fp);

  free(image);

  return 0;
}