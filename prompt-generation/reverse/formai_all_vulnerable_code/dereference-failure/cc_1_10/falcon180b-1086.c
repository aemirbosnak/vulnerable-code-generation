//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 2
#define NUM_PIXELS (WIDTH * HEIGHT)

typedef struct {
  int x, y;
} Pixel;

typedef struct {
  Pixel *pixels;
  int num_pixels;
} Image;

void init_image(Image *image) {
  image->pixels = (Pixel *) malloc(NUM_PIXELS * sizeof(Pixel));
  image->num_pixels = NUM_PIXELS;
}

void free_image(Image *image) {
  free(image->pixels);
}

void set_pixel(Image *image, int x, int y, int color) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    image->pixels[(y * WIDTH) + x].x = x;
    image->pixels[(y * WIDTH) + x].y = y;
  }
}

void generate_art(Image *image) {
  int i, j, k;
  srand(time(NULL));

  for (i = 0; i < NUM_PIXELS; i++) {
    image->pixels[i].x = rand() % WIDTH;
    image->pixels[i].y = rand() % HEIGHT;
  }

  for (k = 0; k < 10; k++) {
    for (i = 0; i < NUM_PIXELS; i++) {
      j = rand() % NUM_PIXELS;
      Pixel temp = image->pixels[i];
      image->pixels[i] = image->pixels[j];
      image->pixels[j] = temp;
    }
  }
}

void draw_image(Image *image) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      int index = (i * WIDTH) + j;
      if (image->pixels[index].x == i && image->pixels[index].y == j) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  Image image;
  init_image(&image);
  generate_art(&image);
  draw_image(&image);
  free_image(&image);
  return 0;
}