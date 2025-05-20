//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint8_t *data;
  int width, height;
} Image;

Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;

  Image *img = malloc(sizeof(Image));
  if (!img) return NULL;

  fread(&img->width, sizeof(int), 1, fp);
  fread(&img->height, sizeof(int), 1, fp);

  img->data = malloc(img->width * img->height);
  if (!img->data) return NULL;

  fread(img->data, sizeof(uint8_t), img->width * img->height, fp);

  fclose(fp);

  return img;
}

void save_image(const Image *img, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) return;

  fwrite(&img->width, sizeof(int), 1, fp);
  fwrite(&img->height, sizeof(int), 1, fp);
  fwrite(img->data, sizeof(uint8_t), img->width * img->height, fp);

  fclose(fp);
}

void flip_image(Image *img) {
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width / 2; x++) {
      uint8_t tmp = img->data[y * img->width + x];
      img->data[y * img->width + x] = img->data[y * img->width + img->width - x - 1];
      img->data[y * img->width + img->width - x - 1] = tmp;
    }
  }
}

void adjust_brightness(Image *img, int offset) {
  for (int i = 0; i < img->width * img->height; i++) {
    int value = img->data[i] + offset;
    if (value < 0) value = 0;
    if (value > 255) value = 255;
    img->data[i] = value;
  }
}

void adjust_contrast(Image *img, float factor) {
  for (int i = 0; i < img->width * img->height; i++) {
    int value = (img->data[i] - 128) * factor + 128;
    if (value < 0) value = 0;
    if (value > 255) value = 255;
    img->data[i] = value;
  }
}

int main() {
  Image *img = load_image("input.bmp");
  if (!img) return 1;

  flip_image(img);
  adjust_brightness(img, 50);
  adjust_contrast(img, 1.5);

  save_image(img, "output.bmp");

  free(img->data);
  free(img);

  return 0;
}