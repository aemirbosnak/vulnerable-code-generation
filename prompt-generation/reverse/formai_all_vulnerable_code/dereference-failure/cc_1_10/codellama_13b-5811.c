//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: unmistakable
// Unique C Image Editor Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int width;
  int height;
  int pixel_size;
  unsigned char *pixels;
} Image;

void display_image(Image *image) {
  int i, j;
  for (i = 0; i < image->height; i++) {
    for (j = 0; j < image->width; j++) {
      unsigned char *pixel = &image->pixels[i * image->width * image->pixel_size + j * image->pixel_size];
      printf("%d ", *pixel);
    }
    printf("\n");
  }
}

void edit_image(Image *image, int x, int y, int value) {
  int pixel_index = y * image->width * image->pixel_size + x * image->pixel_size;
  unsigned char *pixel = &image->pixels[pixel_index];
  *pixel = value;
}

int main(int argc, char *argv[]) {
  int width = 5;
  int height = 5;
  int pixel_size = 3;
  int i, j;

  Image image;
  image.width = width;
  image.height = height;
  image.pixel_size = pixel_size;
  image.pixels = (unsigned char *)malloc(width * height * pixel_size);

  for (i = 0; i < image.height; i++) {
    for (j = 0; j < image.width; j++) {
      unsigned char *pixel = &image.pixels[i * image.width * image.pixel_size + j * image.pixel_size];
      *pixel = (i * image.width + j) % 256;
    }
  }

  display_image(&image);

  edit_image(&image, 2, 2, 255);

  display_image(&image);

  free(image.pixels);

  return 0;
}