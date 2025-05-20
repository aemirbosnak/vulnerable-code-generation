//FormAI DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the complex modulus of a given complex number
double mod(double real, double imag) {
    return sqrt(real*real + imag*imag);
}

// Function to calculate the complex square of a given complex number
void square(double *real, double *imag) {
    double r = *real, i = *imag;
    *real = r*r - i*i;
    *imag = 2*r*i;
}

// Function to check if a given complex number belongs to the Mandelbrot set
int belongs_to_mandelbrot(double real, double imag, int max_iterations) {
    double z_real = real, z_imag = imag, temp;
    int i;
    for (i=0; i<max_iterations; i++) {
        square(&z_real, &z_imag);
        z_real += real;
        z_imag += imag;
        if (mod(z_real, z_imag) > 2) {
            return 0;
        }
    }
    return 1;
}

// Function to generate the Mandelbrot set
void generate_mandelbrot_set(double real_min, double real_max, double imag_min, double imag_max, int columns, int rows, int max_iterations) {
    int i, j;
    double real, imag;
    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
            real = real_min + (double)j/columns*(real_max-real_min);
            imag = imag_min + (double)i/rows*(imag_max-imag_min);
            if (belongs_to_mandelbrot(real, imag, max_iterations)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Main function to generate the Mandelbrot set
int main() {
    double real_min, real_max, imag_min, imag_max;
    int columns, rows, max_iterations;
    printf("Enter the range of the real axis (minimum maximum): ");
    scanf("%lf %lf", &real_min, &real_max);
    printf("Enter the range of the imaginary axis (minimum maximum): ");
    scanf("%lf %lf", &imag_min, &imag_max);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);
    generate_mandelbrot_set(real_min, real_max, imag_min, imag_max, columns, rows, max_iterations);
    return 0;
}