//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000
#define COLOR_MAP_SIZE 256

int mandelbrot_escape_time(double x, double y)
{
    int iter = 0;
    double zx = 0, zy = 0;

    while (iter < MAX_ITER && zx * zx + zy * zy < 4) {
        double temp = zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = temp;
        iter++;
    }

    return iter;
}

void generate_fractal(double xmin, double xmax, double ymin, double ymax)
{
    FILE *fp = fopen("fractal.ppm", "wb");

    if (!fp) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, COLOR_MAP_SIZE);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = xmin + (xmax - xmin) * x / (WIDTH - 1);
            double cy = ymin + (ymax - ymin) * y / (HEIGHT - 1);

            int color = mandelbrot_escape_time(cx, cy) % COLOR_MAP_SIZE;

            fprintf(fp, "%c%c%c", (char)((color >> 16) & 0xFF), (char)((color >> 8) & 0xFF), (char)(color & 0xFF));
        }
    }

    fclose(fp);
}

int main()
{
    double xmin, xmax, ymin, ymax;

    printf("Enter the coordinates of the fractal region:\n");
    printf("xmin: ");
    scanf("%lf", &xmin);
    printf("xmax: ");
    scanf("%lf", &xmax);
    printf("ymin: ");
    scanf("%lf", &ymin);
    printf("ymax: ");
    scanf("%lf", &ymax);

    generate_fractal(xmin, xmax, ymin, ymax);

    printf("Fractal generated successfully!\n");

    return 0;
}