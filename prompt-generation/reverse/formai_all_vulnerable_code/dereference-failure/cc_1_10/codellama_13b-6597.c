//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: authentic
// Fractal Generation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define WIDTH 800
#define HEIGHT 600

// Struct to store pixel data
typedef struct {
  int x;
  int y;
  unsigned char r;
  unsigned char g;
  unsigned char b;
} pixel;

// Function to generate fractal image
void generate_fractal(int iter, pixel* img) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      double x = (double)j / WIDTH * 4 - 2;
      double y = (double)i / HEIGHT * 4 - 2;
      double zx = 0, zy = 0, zx2 = 0, zy2 = 0;
      int count = 0;
      while (count < iter && (zx2 + zy2 < 4)) {
        zy = 2 * zx * zy + y;
        zx = zx2 - zy2 + x;
        zx2 = zx * zx;
        zy2 = zy * zy;
        count++;
      }
      img[i * WIDTH + j].r = 0;
      img[i * WIDTH + j].g = 0;
      img[i * WIDTH + j].b = 255 * count / iter;
    }
  }
}

// Function to save image to file
void save_image(char* filename, pixel* img) {
  int i, j;
  FILE* f = fopen(filename, "w");
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      fprintf(f, "%c%c%c", img[i * WIDTH + j].r, img[i * WIDTH + j].g, img[i * WIDTH + j].b);
    }
  }
  fclose(f);
}

int main() {
  // Allocate memory for image
  pixel* img = malloc(sizeof(pixel) * WIDTH * HEIGHT);
  // Generate fractal image
  generate_fractal(MAX_ITER, img);
  // Save image to file
  save_image("fractal.ppm", img);
  // Free memory
  free(img);
  return 0;
}