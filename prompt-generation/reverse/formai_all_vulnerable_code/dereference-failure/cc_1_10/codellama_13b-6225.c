//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: systematic
/*
* Fractal Generation Program
*
* This program generates a fractal image using the Mandelbrot set algorithm.
* The program takes in a width and height as command-line arguments and
* outputs a PPM image file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a fractal image
void generate_fractal(int width, int height) {
  // Allocate memory for the image
  char *image = malloc(width * height * 3);

  // Iterate over each pixel in the image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the real and imaginary parts of the complex number
      double cr = (double)x / width * 3.5 - 2.5;
      double ci = (double)y / height * 2.0 - 1.0;

      // Iterate over each iteration of the Mandelbrot set
      int iter = 0;
      double zr = 0.0;
      double zi = 0.0;
      while (iter < 1000 && zr * zr + zi * zi < 4.0) {
        double temp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        iter++;
      }

      // Calculate the color of the pixel based on the iteration
      int color = iter * 255 / 1000;
      image[y * width * 3 + x * 3] = color;
      image[y * width * 3 + x * 3 + 1] = color;
      image[y * width * 3 + x * 3 + 2] = color;
    }
  }

  // Write the image to a file
  FILE *file = fopen("fractal.ppm", "wb");
  fprintf(file, "P6\n%d %d\n255\n", width, height);
  fwrite(image, 3, width * height, file);
  fclose(file);

  // Free memory
  free(image);
}

int main(int argc, char **argv) {
  // Check if the command-line arguments are valid
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <width> <height>\n", argv[0]);
    return 1;
  }

  // Convert the command-line arguments to integers
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  // Generate the fractal image
  generate_fractal(width, height);

  return 0;
}