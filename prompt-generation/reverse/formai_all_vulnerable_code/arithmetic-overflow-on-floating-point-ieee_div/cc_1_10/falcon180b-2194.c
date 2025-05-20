//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

// Function to calculate the Mandelbrot set
int mandelbrot(double x, double y) {
    double real = 0, imag = 0;
    int iterations = 0;

    while (iterations < MAX_ITERATIONS && (real * real + imag * imag) < 4) {
        double temp_real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp_real;
        iterations++;
    }

    return iterations;
}

// Function to generate the fractal image
void generate_fractal(int width, int height, double x_min, double x_max, double y_min, double y_max) {
    FILE *fp = fopen("fractal.pbm", "wb");

    if (!fp) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", width, height, 255);

    double x_scale = (x_max - x_min) / (double)width;
    double y_scale = (y_max - y_min) / (double)height;

    for (int x = 0; x < width; x++) {
        double real = x_min + x * x_scale;
        for (int y = 0; y < height; y++) {
            double imag = y_min + y * y_scale;
            int value = mandelbrot(real, imag);
            fprintf(fp, "%c", value % 256);
        }
    }

    fclose(fp);
}

int main() {
    int width, height;
    double x_min, x_max, y_min, y_max;

    // Get user input for image dimensions and range
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the x-axis minimum value: ");
    scanf("%lf", &x_min);
    printf("Enter the x-axis maximum value: ");
    scanf("%lf", &x_max);
    printf("Enter the y-axis minimum value: ");
    scanf("%lf", &y_min);
    printf("Enter the y-axis maximum value: ");
    scanf("%lf", &y_max);

    // Generate the fractal image
    generate_fractal(width, height, x_min, x_max, y_min, y_max);

    printf("Fractal image generated successfully!\n");
    return 0;
}