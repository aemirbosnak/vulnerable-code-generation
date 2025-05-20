//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
  int width;
  int height;
  unsigned char *data;
} Image;

Image *read_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    fclose(fp);
    return NULL;
  }

  fscanf(fp, "P5\n%d %d\n255\n", &image->width, &image->height);

  image->data = malloc(image->width * image->height);
  if (image->data == NULL) {
    free(image);
    fclose(fp);
    return NULL;
  }

  fread(image->data, 1, image->width * image->height, fp);
  fclose(fp);

  return image;
}

void write_image(const Image *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    return;
  }

  fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);
  fwrite(image->data, 1, image->width * image->height, fp);
  fclose(fp);
}

void brighten_image(Image *image, int amount) {
  for (int i = 0; i < image->width * image->height; i++) {
    image->data[i] = image->data[i] + amount;
    if (image->data[i] > 255) {
      image->data[i] = 255;
    }
  }
}

void darken_image(Image *image, int amount) {
  for (int i = 0; i < image->width * image->height; i++) {
    image->data[i] = image->data[i] - amount;
    if (image->data[i] < 0) {
      image->data[i] = 0;
    }
  }
}

void invert_image(Image *image) {
  for (int i = 0; i < image->width * image->height; i++) {
    image->data[i] = 255 - image->data[i];
  }
}

int main(int argc, char **argv) {
  if (argc < 4) {
    printf("Usage: %s <input image> <output image> <command>\n", argv[0]);
    return 1;
  }

  Image *image = read_image(argv[1]);
  if (image == NULL) {
    printf("Could not read image: %s\n", argv[1]);
    return 1;
  }

  if (strcmp(argv[3], "brighten") == 0) {
    brighten_image(image, atoi(argv[4]));
  } else if (strcmp(argv[3], "darken") == 0) {
    darken_image(image, atoi(argv[4]));
  } else if (strcmp(argv[3], "invert") == 0) {
    invert_image(image);
  } else {
    printf("Unknown command: %s\n", argv[3]);
    return 1;
  }

  write_image(image, argv[2]);
  free(image->data);
  free(image);

  return 0;
}