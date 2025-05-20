//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: active
/*
 * Fractal Generation Example Program in C
 *
 * Generates a fractal image using the mandelbrot set algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 100
#define MIN_RE 0.0
#define MAX_RE 2.0
#define MIN_IM -1.0
#define MAX_IM 1.0
#define MAX_COLOR 255

/*
 * Function to calculate the mandelbrot set for a given complex number
 */
int mandelbrot(double re, double im) {
  int iteration = 0;
  double zr = 0.0, zi = 0.0;

  while (iteration < MAX_ITERATIONS && (zr * zr + zi * zi) < 4.0) {
    double new_zr = zr * zr - zi * zi + re;
    double new_zi = 2.0 * zr * zi + im;
    zr = new_zr;
    zi = new_zi;
    iteration++;
  }

  return iteration;
}

/*
 * Function to generate the fractal image
 */
void generate_fractal(int *image) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      double re = MIN_RE + (MAX_RE - MIN_RE) * (x / (double)WIDTH);
      double im = MIN_IM + (MAX_IM - MIN_IM) * (y / (double)HEIGHT);
      int iteration = mandelbrot(re, im);
      int color = iteration * MAX_COLOR / MAX_ITERATIONS;
      image[y * WIDTH + x] = color;
    }
  }
}

/*
 * Main function to run the program
 */
int main() {
  int *image = malloc(WIDTH * HEIGHT * sizeof(int));
  generate_fractal(image);

  // Print the image to the console
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%d ", image[y * WIDTH + x]);
    }
    printf("\n");
  }

  free(image);
  return 0;
}