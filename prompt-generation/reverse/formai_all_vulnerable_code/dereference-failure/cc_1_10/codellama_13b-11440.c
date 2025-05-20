//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: introspective
// Fractal Generation in C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Constants
#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 100
#define MAX_ZOOM 20
#define MAX_COLOR 255

// Function to generate a random color
void get_random_color(int *r, int *g, int *b) {
    *r = rand() % MAX_COLOR;
    *g = rand() % MAX_COLOR;
    *b = rand() % MAX_COLOR;
}

// Function to generate a fractal image
void generate_fractal(int *image) {
    // Initialize the image to black
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = 0;
    }

    // Iterate over the image and generate the fractal
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Get the current pixel coordinates
            double x = (double)i / WIDTH;
            double y = (double)j / HEIGHT;

            // Iterate over the iterations
            for (int iter = 0; iter < MAX_ITER; iter++) {
                // Get the current iteration color
                int r, g, b;
                get_random_color(&r, &g, &b);

                // Apply the fractal transformation
                double xn = x * x - y * y;
                double yn = 2 * x * y;

                // Check if the point is inside the Mandelbrot set
                if (xn * xn + yn * yn > 4) {
                    // If the point is outside the set, use the current iteration color
                    image[i + j * WIDTH] = r << 16 | g << 8 | b;
                    break;
                }
            }
        }
    }
}

// Main function
int main() {
    // Initialize the image array
    int *image = (int *)malloc(WIDTH * HEIGHT * sizeof(int));

    // Generate the fractal image
    generate_fractal(image);

    // Write the image to a file
    FILE *f = fopen("mandelbrot.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(int), WIDTH * HEIGHT, f);
    fclose(f);

    // Free the image array
    free(image);

    return 0;
}