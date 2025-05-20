//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
/*
 * C Basic Image Processing: Flipping an Image
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  int width;
  int height;
  int *data;
} Image;

Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Read the width and height from the file
  int width, height;
  fscanf(fp, "%d %d", &width, &height);

  // Allocate memory for the image
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->data = malloc(width * height * sizeof(int));

  // Read the pixel data from the file
  fread(image->data, sizeof(int), width * height, fp);

  fclose(fp);
  return image;
}

void flip_image(Image *image) {
  int *data = image->data;
  int width = image->width;
  int height = image->height;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      int tmp = data[i * width + j];
      data[i * width + j] = data[i * width + (width - j - 1)];
      data[i * width + (width - j - 1)] = tmp;
    }
  }
}

void save_image(Image *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  // Write the width and height to the file
  fprintf(fp, "%d %d\n", image->width, image->height);

  // Write the pixel data to the file
  fwrite(image->data, sizeof(int), image->width * image->height, fp);

  fclose(fp);
}

int main() {
  Image *image = load_image("input.ppm");
  flip_image(image);
  save_image(image, "output.ppm");
  free(image->data);
  free(image);
  return 0;
}