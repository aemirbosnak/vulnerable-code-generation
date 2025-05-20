//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int main() {
    srand(time(NULL));
    int width, height, max_iterations, x, y, iterations;
    float real, imag, temp_real, temp_imag;
    char filename[20];

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            real = (float)x / width * 3.5 - 2.0;
            imag = (float)y / height * 2.0 - 1.0;

            iterations = 0;

            while (iterations < max_iterations && sqrt(real*real + imag*imag) < 2.0) {
                temp_real = real*real - imag*imag + (float)rand() / RAND_MAX;
                temp_imag = 2.0 * real * imag + (float)rand() / RAND_MAX;

                real = temp_real;
                imag = temp_imag;

                iterations++;
            }

            fprintf(fp, "%d ", iterations % 8);
        }
    }

    fclose(fp);

    return 0;
}