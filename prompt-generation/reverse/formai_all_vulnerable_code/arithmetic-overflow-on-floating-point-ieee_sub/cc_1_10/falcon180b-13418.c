//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Function to calculate the Mandelbrot fractal
void mandelbrot(int x, int y, double *cr, double *ci, int iter) {
    double real = 0, imag = 0;
    for (int i = 0; i < iter; i++) {
        double temp_real = real * real - imag * imag + x;
        imag = 2 * real * imag + y;
        real = temp_real;
        if (real * real + imag * imag > 4) {
            break;
        }
    }
    *cr = real;
    *ci = imag;
}

// Function to generate the fractal image
void generate_fractal(double xmin, double xmax, double ymin, double ymax, int width, int height, int max_iter) {
    FILE *fp = fopen("fractal.ppm", "wb");
    if (fp == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    double x_step = (xmax - xmin) / width;
    double y_step = (ymax - ymin) / height;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            double cr = xmin + x * x_step;
            double ci = ymin + y * y_step;
            int iter = 0;
            mandelbrot(x, y, &cr, &ci, max_iter);

            double r = iter % 8 * 32;
            double g = iter % 16 * 16;
            double b = iter % 32 * 8;

            fprintf(fp, "%c%c%c", (int)r, (int)g, (int)b);
        }
    }

    fclose(fp);
}

int main() {
    double xmin, xmax, ymin, ymax;
    printf("Enter the x and y limits for the fractal (in the form xmin,xmax,ymin,ymax): ");
    scanf("%lf,%lf,%lf,%lf", &xmin, &xmax, &ymin, &ymax);

    generate_fractal(xmin, xmax, ymin, ymax, WIDTH, HEIGHT, MAX_ITER);

    printf("Fractal image generated successfully!\n");
    return 0;
}