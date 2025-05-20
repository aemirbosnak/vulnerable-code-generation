//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_COLORS 256

typedef struct {
  int r;
  int g;
  int b;
} Pixel;

typedef struct {
  int width;
  int height;
  Pixel *pixels;
} Image;

void load_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("Failed to open file %s\n", filename);
    return;
  }

  fscanf(file, "%d %d", &image->width, &image->height);
  image->pixels = malloc(image->width * image->height * sizeof(Pixel));
  if (!image->pixels) {
    printf("Failed to allocate memory for image pixels\n");
    return;
  }

  for (int i = 0; i < image->width * image->height; i++) {
    fscanf(file, "%d %d %d", &image->pixels[i].r, &image->pixels[i].g, &image->pixels[i].b);
  }

  fclose(file);
}

void save_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "w");
  if (!file) {
    printf("Failed to open file %s\n", filename);
    return;
  }

  fprintf(file, "%d %d\n", image->width, image->height);
  for (int i = 0; i < image->width * image->height; i++) {
    fprintf(file, "%d %d %d\n", image->pixels[i].r, image->pixels[i].g, image->pixels[i].b);
  }

  fclose(file);
}

void grayscale(Image *image) {
  for (int i = 0; i < image->width * image->height; i++) {
    Pixel *pixel = &image->pixels[i];
    int gray = (pixel->r + pixel->g + pixel->b) / 3;
    pixel->r = gray;
    pixel->g = gray;
    pixel->b = gray;
  }
}

void invert(Image *image) {
  for (int i = 0; i < image->width * image->height; i++) {
    Pixel *pixel = &image->pixels[i];
    pixel->r = 255 - pixel->r;
    pixel->g = 255 - pixel->g;
    pixel->b = 255 - pixel->b;
  }
}

void median_filter(Image *image, int size) {
  if (size % 2 == 0) {
    size++;
  }
  int half_size = size / 2;
  for (int i = 0; i < image->width; i++) {
    for (int j = 0; j < image->height; j++) {
      int sum_r = 0;
      int sum_g = 0;
      int sum_b = 0;
      for (int k = 0; k < size; k++) {
        for (int l = 0; l < size; l++) {
          int idx = (i + k - half_size) + (j + l - half_size) * image->width;
          if (idx < 0 || idx >= image->width * image->height) {
            continue;
          }
          Pixel *pixel = &image->pixels[idx];
          sum_r += pixel->r;
          sum_g += pixel->g;
          sum_b += pixel->b;
        }
      }
      int median_r = sum_r / (size * size);
      int median_g = sum_g / (size * size);
      int median_b = sum_b / (size * size);
      image->pixels[i + j * image->width].r = median_r;
      image->pixels[i + j * image->width].g = median_g;
      image->pixels[i + j * image->width].b = median_b;
    }
  }
}

int main() {
  Image image;
  load_image(&image, "image.ppm");
  grayscale(&image);
  invert(&image);
  median_filter(&image, 5);
  save_image(&image, "image_processed.ppm");
  free(image.pixels);
  return 0;
}