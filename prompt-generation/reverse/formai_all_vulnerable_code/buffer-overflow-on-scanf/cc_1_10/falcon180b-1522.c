//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

// Function to generate fractal using Mandelbrot set
void mandelbrot(int x, int y, int max_iterations) {
    int i;
    double real = 0, imag = 0;
    double temp_real, temp_imag;

    for (i = 0; i < max_iterations; i++) {
        temp_real = real * real - imag * imag + x;
        temp_imag = 2 * real * imag + y;
        real = temp_real;
        imag = temp_imag;

        if (real * real + imag * imag > 4) {
            break;
        }
    }

    if (i == max_iterations) {
        printf(" ");
    } else {
        printf("#");
    }
}

// Function to generate fractal using Julia set
void julia(int x, int y, int max_iterations, double c_real, double c_imag) {
    int i;
    double z_real = 0, z_imag = 0;

    for (i = 0; i < max_iterations; i++) {
        z_real = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;

        if (z_real * z_real + z_imag * z_imag > 4) {
            break;
        }
    }

    if (i == max_iterations) {
        printf(" ");
    } else {
        printf("#");
    }
}

int main() {
    int x, y, max_iterations;
    double c_real, c_imag;

    // Get user input for fractal type and parameters
    printf("Enter fractal type (Mandelbrot or Julia): ");
    scanf("%s", &c_real);

    if (c_real == 'M') {
        printf("Enter maximum iterations: ");
        scanf("%d", &max_iterations);
    } else {
        printf("Enter real and imaginary components of constant c: ");
        scanf("%lf %lf", &c_real, &c_imag);
        printf("Enter maximum iterations: ");
        scanf("%d", &max_iterations);
    }

    // Generate fractal
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (c_real == 'M') {
                mandelbrot(x, y, max_iterations);
            } else {
                julia(x, y, max_iterations, c_real, c_imag);
            }
        }
    }

    return 0;
}