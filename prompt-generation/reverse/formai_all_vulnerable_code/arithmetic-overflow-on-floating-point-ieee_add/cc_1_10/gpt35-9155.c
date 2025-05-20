//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 1000

// Modular Function to calculate the Mandelbrot Set
int mandelbrot(double realPart, double imaginaryPart) {
    double zReal = 0.0, zImaginary = 0.0;
    double tempReal, tempImaginary;
    int i;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        tempReal = zReal * zReal - zImaginary * zImaginary + realPart;
        tempImaginary = 2.0 * zReal * zImaginary + imaginaryPart;
        zReal = tempReal;
        zImaginary = tempImaginary;

        if (zReal * zReal + zImaginary * zImaginary > 4.0) {
            return 0;
        }
    }
    return 1;
}

// Function to print fractal
void printFractal(char fractal[][WIDTH]) {
    int i, j;
    printf("\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to generate the fractal
void generateFractal(char fractal[][WIDTH], double minReal, double maxReal,
                     double minImaginary, double maxImaginary) {
    double realInterval = (maxReal - minReal) / (WIDTH - 1);
    double imaginaryInterval = (maxImaginary - minImaginary) / (HEIGHT - 1);
    double realPart, imaginaryPart;
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        imaginaryPart = maxImaginary - i * imaginaryInterval;
        for (j = 0; j < WIDTH; j++) {
            realPart = minReal + j * realInterval;
            fractal[i][j] = mandelbrot(realPart, imaginaryPart) ? '*' : ' ';
        }
    }
    printFractal(fractal);
}

// Driver function
int main() {
    char fractal[HEIGHT][WIDTH];
    double minReal, maxReal, minImaginary, maxImaginary;

    printf("Enter the minimum and maximum real values:\n");
    scanf("%lf %lf", &minReal, &maxReal);

    printf("Enter the minimum and maximum imaginary values:\n");
    scanf("%lf %lf", &minImaginary, &maxImaginary);

    generateFractal(fractal, minReal, maxReal, minImaginary, maxImaginary);

    return 0;
}