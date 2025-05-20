//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int mandelbrot(double x, double y) {
    int iterations = 0;
    double real = 0.0, imag = 0.0;

    for (int i = 0; i < MAX_ITERATIONS; ++i) {
        double temp_real = real * real - imag * imag + x;
        imag = 2.0 * real * imag + y;
        real = temp_real;

        if (real * real + imag * imag > 4.0) {
            break;
        }

        ++iterations;
    }

    return iterations;
}

void generate_fractal(double x_min, double x_max, double y_min, double y_max) {
    FILE *output = fopen("fractal.ppm", "wb");

    if (output == NULL) {
        printf("Error: could not create output file.\n");
        exit(1);
    }

    fprintf(output, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            double c_real = x_min + (x_max - x_min) * x / (WIDTH - 1);
            double c_imag = y_min + (y_max - y_min) * y / (HEIGHT - 1);

            int value = mandelbrot(c_real, c_imag);
            double color_scale = (double)value / MAX_ITERATIONS;

            fprintf(output, "%c%c%c", (int)(255 * color_scale), (int)(255 * color_scale), (int)(255 * color_scale));
        }
    }

    fclose(output);
}

int main() {
    double x_min, x_max, y_min, y_max;

    printf("Enter the coordinates of the rectangle to generate the fractal for:\n");
    printf("x_min: ");
    scanf("%lf", &x_min);
    printf("x_max: ");
    scanf("%lf", &x_max);
    printf("y_min: ");
    scanf("%lf", &y_min);
    printf("y_max: ");
    scanf("%lf", &y_max);

    generate_fractal(x_min, x_max, y_min, y_max);

    printf("Fractal generated successfully!\n");

    return 0;
}