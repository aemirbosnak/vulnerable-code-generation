//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_COLOR 255

typedef struct {
  unsigned char r, g, b, a;
} Pixel;

typedef struct {
  Pixel *data;
  int width, height;
} Image;

Image *createImage(int width, int height) {
  Image *img = (Image *)malloc(sizeof(Image));
  img->data = (Pixel *)malloc(width * height * sizeof(Pixel));
  img->width = width;
  img->height = height;
  return img;
}

void freeImage(Image *img) {
  free(img->data);
  free(img);
}

void setPixel(Image *img, int x, int y, Pixel color) {
  img->data[x + y * img->width] = color;
}

Pixel getPixel(Image *img, int x, int y) {
  return img->data[x + y * img->width];
}

void blurImage(Image *img, int blur_amount) {
  int width = img->width;
  int height = img->height;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int blurred_color = 0;

      for (int i = -blur_amount; i <= blur_amount; i++) {
        for (int j = -blur_amount; j <= blur_amount; j++) {
          int neighbor_x = x + i;
          int neighbor_y = y + j;

          if (neighbor_x >= 0 && neighbor_x < width && neighbor_y >= 0 && neighbor_y < height) {
            Pixel neighbor = getPixel(img, neighbor_x, neighbor_y);
            blurred_color += neighbor.r;
            blurred_color += neighbor.g;
            blurred_color += neighbor.b;
          }
        }
      }

      blurred_color /= (blur_amount * 2 + 1) * (blur_amount * 2 + 1);

      Pixel blurred_pixel;
      blurred_pixel.r = blurred_color;
      blurred_pixel.g = blurred_color;
      blurred_pixel.b = blurred_color;

      setPixel(img, x, y, blurred_pixel);
    }
  }
}

void drawImage(Image *img) {
  int width = img->width;
  int height = img->height;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Pixel pixel = getPixel(img, x, y);
      printf(".");
    }
    printf("\n");
  }
}

int main() {
  Image *img = createImage(WIDTH, HEIGHT);

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      Pixel pixel;
      pixel.r = x % MAX_COLOR;
      pixel.g = y % MAX_COLOR;
      pixel.b = (x + y) % MAX_COLOR;
      setPixel(img, x, y, pixel);
    }
  }

  blurImage(img, 5);

  drawImage(img);

  freeImage(img);

  return 0;
}