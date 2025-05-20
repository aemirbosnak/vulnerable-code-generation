//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define ESCAPE_TIME 4.0

// Function to calculate the value of the fractal at a given point
double fractal(double x, double y) {
    double real = 0.0, imag = 0.0;
    int iter = 0;

    while (iter < MAX_ITER && (real*real + imag*imag < ESCAPE_TIME)) {
        double newReal = real*real - imag*imag + x;
        double newImag = 2.0*real*imag + y;
        real = newReal;
        imag = newImag;
        iter++;
    }

    return iter;
}

// Function to generate the fractal image
void generateFractal(int width, int height, double xMin, double xMax, double yMin, double yMax) {
    FILE *fp = fopen("fractal.pbm", "wb");

    if (!fp) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    double xStep = (xMax - xMin) / (double)width;
    double yStep = (yMax - yMin) / (double)height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double value = fractal(xMin + x*xStep, yMin + y*yStep);
            int color = (int)(255.0 * value / MAX_ITER);

            fprintf(fp, "%c", color);
        }
    }

    fclose(fp);
}

// Main function
int main() {
    int width, height;
    double xMin, xMax, yMin, yMax;

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    printf("Enter the xMin value: ");
    scanf("%lf", &xMin);

    printf("Enter the xMax value: ");
    scanf("%lf", &xMax);

    printf("Enter the yMin value: ");
    scanf("%lf", &yMin);

    printf("Enter the yMax value: ");
    scanf("%lf", &yMax);

    generateFractal(width, height, xMin, xMax, yMin, yMax);

    printf("Fractal image generated successfully!\n");

    return 0;
}