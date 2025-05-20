//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: systematic
/*
 * Fractal Generation Program
 *
 * Generates a fractal image using a systematic approach
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the fractal's parameters
#define MAX_ITER 1000
#define WIDTH 1000
#define HEIGHT 1000
#define MAX_DEPTH 10

// Define the fractal's function
#define FRACTAL(x, y) (sin(x*y) + cos(x*y))

// Define the color palette
#define RED 255
#define GREEN 128
#define BLUE 0

// Define the escape radius
#define ESCAPE_RADIUS 2.0

int main() {
  // Initialize the image
  unsigned char *image = malloc(WIDTH * HEIGHT * 3);

  // Iterate over each pixel in the image
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Calculate the fractal's value at this pixel
      double value = FRACTAL(x, y);

      // Check if the value is within the escape radius
      if (value < ESCAPE_RADIUS) {
        // Calculate the color of the pixel based on its depth
        int depth = MAX_DEPTH * value / ESCAPE_RADIUS;
        int red = RED * depth / MAX_DEPTH;
        int green = GREEN * depth / MAX_DEPTH;
        int blue = BLUE * depth / MAX_DEPTH;

        // Set the pixel's color
        image[(y * WIDTH + x) * 3 + 0] = red;
        image[(y * WIDTH + x) * 3 + 1] = green;
        image[(y * WIDTH + x) * 3 + 2] = blue;
      } else {
        // Set the pixel's color to black
        image[(y * WIDTH + x) * 3 + 0] = 0;
        image[(y * WIDTH + x) * 3 + 1] = 0;
        image[(y * WIDTH + x) * 3 + 2] = 0;
      }
    }
  }

  // Save the image to a file
  FILE *fp = fopen("fractal.ppm", "w");
  fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(image, WIDTH * HEIGHT * 3, 1, fp);
  fclose(fp);

  // Free the image
  free(image);

  return 0;
}