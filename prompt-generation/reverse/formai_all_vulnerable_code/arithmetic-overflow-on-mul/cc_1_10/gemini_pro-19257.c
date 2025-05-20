//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

struct image {
  int width, height;
  byte *data;
};

struct image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;

  struct image *img = malloc(sizeof(struct image));
  if (!img) { fclose(fp); return NULL; }

  fread(&img->width, sizeof(int), 1, fp);
  fread(&img->height, sizeof(int), 1, fp);

  img->data = malloc(img->width * img->height);
  if (!img->data) { free(img); fclose(fp); return NULL; }

  fread(img->data, img->width * img->height, 1, fp);
  fclose(fp);
  return img;
}

void free_image(struct image *img) {
  free(img->data);
  free(img);
}

void flip_horizontal(struct image *img) {
  for (int i = 0; i < img->height; ++i) {
    for (int j = 0; j < img->width / 2; ++j) {
      byte temp = img->data[i * img->width + j];
      img->data[i * img->width + j] = img->data[i * img->width + img->width - j - 1];
      img->data[i * img->width + img->width - j - 1] = temp;
    }
  }
}

void flip_vertical(struct image *img) {
  for (int i = 0; i < img->height / 2; ++i) {
    for (int j = 0; j < img->width; ++j) {
      byte temp = img->data[i * img->width + j];
      img->data[i * img->width + j] = img->data[(img->height - i - 1) * img->width + j];
      img->data[(img->height - i - 1) * img->width + j] = temp;
    }
  }
}

void adjust_brightness(struct image *img, int delta) {
  for (int i = 0; i < img->width * img->height; ++i) {
    int new_value = img->data[i] + delta;
    if (new_value < 0) new_value = 0;
    if (new_value > 255) new_value = 255;
    img->data[i] = new_value;
  }
}

void adjust_contrast(struct image *img, float factor) {
  float mid = 128;
  for (int i = 0; i < img->width * img->height; ++i) {
    float new_value = (img->data[i] - mid) * factor + mid;
    if (new_value < 0) new_value = 0;
    if (new_value > 255) new_value = 255;
    img->data[i] = new_value;
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  struct image *img = load_image(argv[1]);
  if (!img) {
    printf("Error loading image '%s'\n", argv[1]);
    return 1;
  }

  flip_vertical(img);
  flip_horizontal(img);
  adjust_brightness(img, 50);
  adjust_contrast(img, 1.5);

  // ...

  free_image(img);

  return 0;
}