//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_ITERATIONS 1000

// Function to calculate the color of a pixel based on its distance from the Mandelbrot set
int calculate_color(double x, double y, int max_iterations) {
    int iterations = 0;
    double real = 0, imaginary = 0;
    while (iterations < max_iterations && (real * real + imaginary * imaginary) <= 4) {
        double temp_real = real * real - imaginary * imaginary + x;
        imaginary = 2 * real * imaginary + y;
        real = temp_real;
        iterations++;
    }
    return iterations % 8;
}

int main() {
    srand(time(NULL));

    // Get user input for image size and maximum iterations
    int width, height, max_iterations;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Create a new image with the given size and fill it with random colors
    FILE *image_file = fopen("mandelbrot.bmp", "wb");
    if (image_file == NULL) {
        printf("Error: Unable to create image file.\n");
        return 1;
    }
    fprintf(image_file, "BM");
    fwrite(&width, sizeof(int), 1, image_file);
    fwrite(&height, sizeof(int), 1, image_file);
    fwrite(&max_iterations, sizeof(int), 1, image_file);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = calculate_color(x, y, max_iterations);
            fwrite(&color, sizeof(int), 1, image_file);
        }
    }
    fclose(image_file);

    printf("Image saved as mandelbrot.bmp.\n");
    return 0;
}