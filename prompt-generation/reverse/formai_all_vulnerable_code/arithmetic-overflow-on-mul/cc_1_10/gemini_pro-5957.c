//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double r, g, b;
} Pixel;

typedef struct {
  int width, height;
  Pixel *pixels;
} Image;

Image *load_image(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (!image) {
    fclose(file);
    return NULL;
  }

  fread(&image->width, sizeof(int), 1, file);
  fread(&image->height, sizeof(int), 1, file);

  image->pixels = malloc(image->width * image->height * sizeof(Pixel));
  if (!image->pixels) {
    fclose(file);
    free(image);
    return NULL;
  }

  fread(image->pixels, sizeof(Pixel), image->width * image->height, file);

  fclose(file);

  return image;
}

void free_image(Image *image) {
  free(image->pixels);
  free(image);
}

int classify_image(Image *image) {
  double r_avg = 0, g_avg = 0, b_avg = 0;

  for (int i = 0; i < image->width * image->height; i++) {
    r_avg += image->pixels[i].r;
    g_avg += image->pixels[i].g;
    b_avg += image->pixels[i].b;
  }

  r_avg /= image->width * image->height;
  g_avg /= image->width * image->height;
  b_avg /= image->width * image->height;

  double d0 = sqrt((r_avg - 0) * (r_avg - 0) + (g_avg - 0) * (g_avg - 0) + (b_avg - 0) * (b_avg - 0));
  double d1 = sqrt((r_avg - 255) * (r_avg - 255) + (g_avg - 255) * (g_avg - 255) + (b_avg - 255) * (b_avg - 255));

  if (d0 < d1) {
    return 0;  // Black
  } else {
    return 1;  // White
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <image.bmp>\n", argv[0]);
    return 1;
  }

  Image *image = load_image(argv[1]);
  if (!image) {
    printf("Error loading image: %s\n", argv[1]);
    return 1;
  }

  int classification = classify_image(image);

  printf("Image is classified as: %s\n", classification == 0 ? "Black" : "White");

  free_image(image);

  return 0;
}