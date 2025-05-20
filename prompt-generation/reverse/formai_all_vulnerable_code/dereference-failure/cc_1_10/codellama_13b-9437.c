//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: light-weight
/*
 * C Image Editor
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_COLOR_CHANNELS 3
#define MAX_COLOR_DEPTH 8

typedef struct {
  unsigned char r, g, b;
} Color;

typedef struct {
  int width, height;
  Color *pixels;
} Image;

void loadImage(const char *filename, Image *image) {
  FILE *fp = fopen(filename, "rb");
  fread(&image->width, sizeof(int), 1, fp);
  fread(&image->height, sizeof(int), 1, fp);
  image->pixels = (Color *)malloc(image->width * image->height * sizeof(Color));
  fread(image->pixels, sizeof(Color), image->width * image->height, fp);
  fclose(fp);
}

void saveImage(const char *filename, Image *image) {
  FILE *fp = fopen(filename, "wb");
  fwrite(&image->width, sizeof(int), 1, fp);
  fwrite(&image->height, sizeof(int), 1, fp);
  fwrite(image->pixels, sizeof(Color), image->width * image->height, fp);
  fclose(fp);
}

void scaleImage(Image *image, int newWidth, int newHeight) {
  Color *newPixels = (Color *)malloc(newWidth * newHeight * sizeof(Color));
  for (int y = 0; y < newHeight; y++) {
    for (int x = 0; x < newWidth; x++) {
      int oldX = (int)(x * image->width / newWidth);
      int oldY = (int)(y * image->height / newHeight);
      newPixels[y * newWidth + x] = image->pixels[oldY * image->width + oldX];
    }
  }
  free(image->pixels);
  image->pixels = newPixels;
  image->width = newWidth;
  image->height = newHeight;
}

void flipImage(Image *image, int flipX, int flipY) {
  Color *newPixels = (Color *)malloc(image->width * image->height * sizeof(Color));
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int newX = flipX ? image->width - x - 1 : x;
      int newY = flipY ? image->height - y - 1 : y;
      newPixels[newY * image->width + newX] = image->pixels[y * image->width + x];
    }
  }
  free(image->pixels);
  image->pixels = newPixels;
}

void rotateImage(Image *image, int degrees) {
  Color *newPixels = (Color *)malloc(image->width * image->height * sizeof(Color));
  double radians = degrees * M_PI / 180.0;
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      double newX = x * cos(radians) - y * sin(radians);
      double newY = x * sin(radians) + y * cos(radians);
      newX += (image->width - 1) / 2.0;
      newY += (image->height - 1) / 2.0;
      int newXInt = (int)round(newX);
      int newYInt = (int)round(newY);
      if (newXInt >= 0 && newXInt < image->width && newYInt >= 0 && newYInt < image->height) {
        newPixels[y * image->width + x] = image->pixels[newYInt * image->width + newXInt];
      } else {
        newPixels[y * image->width + x] = (Color){0, 0, 0};
      }
    }
  }
  free(image->pixels);
  image->pixels = newPixels;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input_file> <output_file> [operation] [options]\n", argv[0]);
    return 1;
  }
  Image image;
  loadImage(argv[1], &image);
  if (argc > 3) {
    if (strcmp(argv[3], "scale") == 0) {
      int newWidth = atoi(argv[4]);
      int newHeight = atoi(argv[5]);
      scaleImage(&image, newWidth, newHeight);
    } else if (strcmp(argv[3], "flip") == 0) {
      int flipX = strcmp(argv[4], "x") == 0;
      int flipY = strcmp(argv[4], "y") == 0;
      flipImage(&image, flipX, flipY);
    } else if (strcmp(argv[3], "rotate") == 0) {
      int degrees = atoi(argv[4]);
      rotateImage(&image, degrees);
    } else {
      printf("Invalid operation: %s\n", argv[3]);
      return 1;
    }
  }
  saveImage(argv[2], &image);
  return 0;
}