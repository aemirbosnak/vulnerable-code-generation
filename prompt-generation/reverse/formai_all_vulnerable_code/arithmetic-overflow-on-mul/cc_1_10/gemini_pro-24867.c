//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480
#define CHANNELS 3

typedef struct {
  unsigned char *data;
  int width;
  int height;
  int channels;
} Image;

Image *load_image(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (!image) {
    fprintf(stderr, "Error: could not allocate memory for image\n");
    fclose(file);
    return NULL;
  }

  fread(&image->width, sizeof(int), 1, file);
  fread(&image->height, sizeof(int), 1, file);
  fread(&image->channels, sizeof(int), 1, file);

  image->data = malloc(image->width * image->height * image->channels);
  if (!image->data) {
    fprintf(stderr, "Error: could not allocate memory for image data\n");
    free(image);
    fclose(file);
    return NULL;
  }

  fread(image->data, 1, image->width * image->height * image->channels, file);
  fclose(file);

  return image;
}

void save_image(const char *filename, Image *image) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    return;
  }

  fwrite(&image->width, sizeof(int), 1, file);
  fwrite(&image->height, sizeof(int), 1, file);
  fwrite(&image->channels, sizeof(int), 1, file);
  fwrite(image->data, 1, image->width * image->height * image->channels, file);
  fclose(file);
}

void flip_image(Image *image) {
  for (int y = 0; y < image->height / 2; y++) {
    for (int x = 0; x < image->width; x++) {
      for (int c = 0; c < image->channels; c++) {
        unsigned char temp = image->data[y * image->width * image->channels + x * image->channels + c];
        image->data[y * image->width * image->channels + x * image->channels + c] =
            image->data[(image->height - y - 1) * image->width * image->channels + x * image->channels + c];
        image->data[(image->height - y - 1) * image->width * image->channels + x * image->channels + c] = temp;
      }
    }
  }
}

void change_brightness_contrast(Image *image, float brightness, float contrast) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      for (int c = 0; c < image->channels; c++) {
        float value = image->data[y * image->width * image->channels + x * image->channels + c] / 255.0f;
        value = value * contrast + brightness;
        value = fminf(fmaxf(value, 0.0f), 1.0f);
        image->data[y * image->width * image->channels + x * image->channels + c] = value * 255.0f;
      }
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
    return 1;
  }

  Image *image = load_image(argv[1]);
  if (!image) {
    return 1;
  }

  flip_image(image);
  change_brightness_contrast(image, 0.5f, 1.2f);

  save_image(argv[2], image);

  free(image->data);
  free(image);

  return 0;
}