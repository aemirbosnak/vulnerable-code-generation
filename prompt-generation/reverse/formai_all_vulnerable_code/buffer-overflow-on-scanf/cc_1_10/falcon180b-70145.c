//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000
#define COLOR_COUNT 256

int iter = 0;
int x, y;
int max_iter = MAX_ITER;
double zoom = 1.0;
double c_re = -0.70176;
double c_im = 0.3842;

typedef struct {
    double re;
    double im;
} Complex;

Complex mandelbrot(double x, double y) {
    Complex z = {0, 0};
    Complex c = {c_re, c_im};

    for (int i = 0; i < max_iter; i++) {
        Complex temp = {z.re * z.re - z.im * z.im + c.re, 2.0 * z.re * z.im + c.im};
        z = temp;
        if (z.re * z.re + z.im * z.im > 4.0) {
            return z;
        }
    }

    return z;
}

void draw_fractal() {
    FILE *fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, COLOR_COUNT);

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2) * zoom + c_re;
            double imag = (y - HEIGHT / 2) * zoom + c_im;
            Complex z = mandelbrot(real, imag);
            int color = iter % COLOR_COUNT;

            fprintf(fp, "%c%c%c", (int)(255 * z.re), (int)(255 * z.im), (int)(255 * color));
        }
    }

    fclose(fp);
}

int main() {
    printf("Enter the number of iterations: ");
    scanf("%d", &max_iter);

    printf("Enter the zoom factor (1.0 to %d): ", WIDTH / 2);
    scanf("%lf", &zoom);

    draw_fractal();

    return 0;
}