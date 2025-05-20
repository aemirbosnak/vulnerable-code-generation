//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_COLOR 255

int main() {
    int width, height, max_iterations, i, j, k, iterations;
    double x_min, x_max, y_min, y_max, x, y, dx, dy;
    char *filename;
    FILE *fp;
    unsigned char *pixels;

    // Get input from user
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iterations);

    // Allocate memory for image
    pixels = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (pixels == NULL) {
        printf("Error: failed to allocate memory.\n");
        exit(1);
    }

    // Set initial values
    x_min = -2.0;
    x_max = 1.0;
    y_min = -1.5;
    y_max = 1.5;
    x = x_min;
    y = y_min;
    dx = (x_max - x_min) / (double)width;
    dy = (y_max - y_min) / (double)height;

    // Generate fractal image
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            iterations = 0;
            while (iterations < MAX_ITERATIONS && (x * x + y * y) < 4.0) {
                x = x * x - y * y + x_min;
                y = 2.0 * x * y + y_min;
                iterations++;
            }
            if (iterations == MAX_ITERATIONS) {
                pixels[i * width + j] = 0;
            } else {
                pixels[i * width + j] = iterations % MAX_COLOR;
            }
        }
        x = x_min;
        y = y_min;
        x += i * dx;
        y += j * dy;
    }

    // Save image to file
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: failed to open file.\n");
        exit(1);
    }
    fwrite(pixels, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Free memory
    free(pixels);

    return 0;
}