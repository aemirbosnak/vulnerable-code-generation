//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
/*
 * Simple image processing program
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} pixel_t;

typedef struct {
  pixel_t *pixels;
  int width;
  int height;
} image_t;

void read_image(image_t *image, const char *filename) {
  FILE *file = fopen(filename, "rb");
  assert(file);
  fread(image->pixels, sizeof(pixel_t), MAX_IMAGE_SIZE, file);
  fclose(file);
}

void write_image(image_t *image, const char *filename) {
  FILE *file = fopen(filename, "wb");
  assert(file);
  fwrite(image->pixels, sizeof(pixel_t), MAX_IMAGE_SIZE, file);
  fclose(file);
}

void flip_image(image_t *image, int direction) {
  int width = image->width;
  int height = image->height;
  pixel_t *pixels = image->pixels;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      int index1 = i * width + j;
      int index2 = i * width + width - j - 1;
      pixel_t temp = pixels[index1];
      pixels[index1] = pixels[index2];
      pixels[index2] = temp;
    }
  }
}

void change_brightness(image_t *image, int brightness) {
  int width = image->width;
  int height = image->height;
  pixel_t *pixels = image->pixels;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[i * width + j].r += brightness;
      pixels[i * width + j].g += brightness;
      pixels[i * width + j].b += brightness;
    }
  }
}

void change_contrast(image_t *image, float contrast) {
  int width = image->width;
  int height = image->height;
  pixel_t *pixels = image->pixels;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[i * width + j].r = (int)(((pixels[i * width + j].r / 255.0) * contrast) * 255.0);
      pixels[i * width + j].g = (int)(((pixels[i * width + j].g / 255.0) * contrast) * 255.0);
      pixels[i * width + j].b = (int)(((pixels[i * width + j].b / 255.0) * contrast) * 255.0);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <input file> <output file> <operation>\n", argv[0]);
    return 1;
  }

  image_t image;
  image.width = 100;
  image.height = 100;
  image.pixels = malloc(sizeof(pixel_t) * MAX_IMAGE_SIZE);

  read_image(&image, argv[1]);

  if (strcmp(argv[3], "flip") == 0) {
    flip_image(&image, atoi(argv[2]));
  } else if (strcmp(argv[3], "brightness") == 0) {
    change_brightness(&image, atoi(argv[2]));
  } else if (strcmp(argv[3], "contrast") == 0) {
    change_contrast(&image, atof(argv[2]));
  } else {
    printf("Invalid operation: %s\n", argv[3]);
    return 1;
  }

  write_image(&image, argv[2]);

  free(image.pixels);

  return 0;
}