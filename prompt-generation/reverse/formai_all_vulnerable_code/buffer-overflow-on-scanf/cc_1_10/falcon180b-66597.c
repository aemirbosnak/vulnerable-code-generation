//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

// Function to calculate the fractal value
int fractal(double x, double y) {
    int iterations = 0;
    double real = 0.0;
    double imag = 0.0;

    while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4.0) {
        double tempReal = real * real - imag * imag + x;
        imag = 2.0 * real * imag + y;
        real = tempReal;

        iterations++;
    }

    return iterations;
}

// Function to draw the fractal
void drawFractal(int height, int width, double xMin, double xMax, double yMin, double yMax) {
    int row, col;
    double x, y;
    double dx = (xMax - xMin) / (double)height;
    double dy = (yMax - yMin) / (double)width;

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            x = xMin + col * dx;
            y = yMin + row * dy;

            int color = fractal(x, y);

            if (color == MAX_ITERATIONS) {
                printf("  ");
            } else {
                printf("%02X ", color);
            }
        }

        printf("\n");
    }
}

// Main function
int main() {
    int height, width;
    double xMin, xMax, yMin, yMax;

    // Get user input for fractal properties
    printf("Enter the height of the fractal: ");
    scanf("%d", &height);

    printf("Enter the width of the fractal: ");
    scanf("%d", &width);

    printf("Enter the x-axis minimum value: ");
    scanf("%lf", &xMin);

    printf("Enter the x-axis maximum value: ");
    scanf("%lf", &xMax);

    printf("Enter the y-axis minimum value: ");
    scanf("%lf", &yMin);

    printf("Enter the y-axis maximum value: ");
    scanf("%lf", &yMax);

    // Draw the fractal
    drawFractal(height, width, xMin, xMax, yMin, yMax);

    return 0;
}