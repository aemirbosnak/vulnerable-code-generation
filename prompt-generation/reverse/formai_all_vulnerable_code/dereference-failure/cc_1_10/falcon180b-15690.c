//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

// Function to calculate fractal value
int calculate_fractal(int x, int y, int max_iterations) {
    int iterations = 0;
    while (iterations < max_iterations && abs(x) + abs(y) > 0) {
        int new_x = x * x - y * y + 1;
        int new_y = 2 * x * y + 1;
        x = new_x;
        y = new_y;
        iterations++;
    }
    return iterations;
}

int main() {
    int width, height, max_iterations;
    printf("Enter the width of the fractal image: ");
    scanf("%d", &width);
    printf("Enter the height of the fractal image: ");
    scanf("%d", &height);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Allocate memory for the fractal image
    int **fractal_image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        fractal_image[i] = (int *)malloc(width * sizeof(int));
    }

    // Generate the fractal image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int x = (double)j / width * 4 - 2;
            int y = (double)i / height * 3 - 1.5;
            int iterations = calculate_fractal(x, y, max_iterations);
            fractal_image[i][j] = iterations;
        }
    }

    // Save the fractal image to a file
    FILE *fp = fopen("fractal.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(fractal_image[0], sizeof(int), width, fp);
    for (int i = 1; i < height; i++) {
        fwrite(fractal_image[i], sizeof(int), width, fp);
    }
    fclose(fp);

    printf("Fractal image generated and saved to fractal.bmp.\n");

    return 0;
}