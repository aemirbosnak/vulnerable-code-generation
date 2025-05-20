//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITERATIONS 1000
#define MAX_WIDTH 800
#define MAX_HEIGHT 800
#define COLOR_MAX 255

// Function to generate fractal image
void generate_fractal(int width, int height, int max_iterations, int color) {
    int i, j, iterations;
    double real, imag, temp_real, temp_imag;

    // Set initial values for real and imaginary parts
    real = -0.7;
    imag = 0.27;

    // Loop through each pixel in the image
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Set initial values for temp_real and temp_imag
            temp_real = real;
            temp_imag = imag;

            // Calculate fractal value for this pixel
            iterations = 0;
            while (iterations < max_iterations && temp_real * temp_real + temp_imag * temp_imag < 4) {
                temp_real = temp_real * temp_real - temp_imag * temp_imag + real;
                temp_imag = 2 * temp_real * temp_imag + imag;
                iterations++;
            }

            // Set color based on number of iterations
            if (iterations == max_iterations) {
                color = COLOR_MAX - iterations;
            } else {
                color = iterations * (COLOR_MAX / max_iterations);
            }

            // Set pixel color
            printf("%d %d %d\n", color, color, color);
        }
    }
}

int main() {
    int width, height, max_iterations, color;

    // Get user input for image size and maximum iterations
    printf("Enter image width (1-800): ");
    scanf("%d", &width);
    printf("Enter image height (1-800): ");
    scanf("%d", &height);
    printf("Enter maximum iterations (1-%d): ", MAX_ITERATIONS);
    scanf("%d", &max_iterations);

    // Generate fractal image
    srand(time(NULL));
    color = rand() % COLOR_MAX;
    printf("P6\n%d %d\n%d\n", width, height, COLOR_MAX);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            generate_fractal(width, height, max_iterations, color);
        }
    }

    return 0;
}