//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITER 1000

// Define the escape time algorithm threshold
#define THRESHOLD 4.0

// Function to calculate the Mandelbrot value for a given complex number
double mandelbrot(double real, double imag) {
    double z_real = 0.0;
    double z_imag = 0.0;
    int iterations = 0;

    // Initialize the complex numbers
    z_real = real;
    z_imag = imag;

    // Iterate until we reach the maximum number of iterations or the value exceeds the threshold
    while (iterations < MAX_ITER && abs(z_real) + abs(z_imag) < THRESHOLD) {
        double temp_real = z_real * z_real - z_imag * z_imag + real;
        double temp_imag = 2.0 * z_real * z_imag + imag;
        z_real = temp_real;
        z_imag = temp_imag;
        iterations++;
    }

    // Return the number of iterations
    return iterations;
}

int main() {
    int width, height;
    double x_min, x_max, y_min, y_max;
    double dx, dy;
    FILE *fp;
    char filename[50];

    // Get the image dimensions from the user
    printf("Enter the image width: ");
    scanf("%d", &width);
    printf("Enter the image height: ");
    scanf("%d", &height);

    // Get the range of x and y values
    printf("Enter the x minimum value: ");
    scanf("%lf", &x_min);
    printf("Enter the x maximum value: ");
    scanf("%lf", &x_max);
    printf("Enter the y minimum value: ");
    scanf("%lf", &y_min);
    printf("Enter the y maximum value: ");
    scanf("%lf", &y_max);

    // Calculate the step size for each pixel
    dx = (x_max - x_min) / (double)width;
    dy = (y_max - y_min) / (double)height;

    // Allocate memory for the image data
    unsigned char *data = (unsigned char *)malloc(width * height * sizeof(unsigned char));

    // Iterate over each pixel in the image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the complex number for this pixel
            double real = x_min + x * dx;
            double imag = y_min + y * dy;

            // Calculate the Mandelbrot value for this pixel
            int value = mandelbrot(real, imag);

            // Map the value to a grayscale color
            double gray = (double)value / MAX_ITER;
            unsigned char color = (unsigned char)(255 * gray);

            // Set the pixel color in the image data
            data[y * width + x] = color;
        }
    }

    // Save the image to a file
    sprintf(filename, "mandelbrot_%dx%d.bmp", width, height);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(data, sizeof(unsigned char), width * height, fp);

    fclose(fp);

    printf("Image saved to file: %s\n", filename);

    return 0;
}