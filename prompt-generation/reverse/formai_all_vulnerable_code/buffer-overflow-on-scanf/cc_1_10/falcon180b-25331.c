//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000
#define COLOR_MAX 255

int mandelbrot(double real, double imag) {
    double zr = 0, zi = 0;
    int iterations = 0;
    
    while (iterations < MAX_ITERATIONS && (zr * zr + zi * zi) < 4) {
        double tr = zr * zr - zi * zi + real;
        zi = 2 * zr * zi + imag;
        zr = tr;
        iterations++;
    }
    
    return iterations % COLOR_MAX;
}

void generate_fractal(double xmin, double xmax, double ymin, double ymax) {
    FILE *fp = fopen("fractal.ppm", "wb");
    
    if (!fp) {
        fprintf(stderr, "Error: could not open output file.\n");
        exit(EXIT_FAILURE);
    }
    
    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, COLOR_MAX);
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = xmin + (xmax - xmin) * x / (WIDTH - 1);
            double cy = ymin + (ymax - ymin) * y / (HEIGHT - 1);
            
            int color = mandelbrot(cx, cy);
            
            fprintf(fp, "%d ", color);
        }
    }
    
    fclose(fp);
}

int main() {
    double xmin, xmax, ymin, ymax;

    printf("Enter the minimum and maximum values for x and y coordinates:\n");
    scanf("%lf %lf %lf %lf", &xmin, &xmax, &ymin, &ymax);

    generate_fractal(xmin, xmax, ymin, ymax);

    printf("Fractal image generated successfully!\n");

    return 0;
}