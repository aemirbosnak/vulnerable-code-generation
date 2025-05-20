//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
    double real;
    double imag;
} Complex;

Complex cadd(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex cmul(Complex a, Complex b) {
    return (Complex){a.real * b.real - a.imag * b.imag,
                     a.real * b.imag + a.imag * b.real};
}

double cabs(Complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

void mandelbrot(int width, int height, double xmin, double xmax, double ymin, double ymax) {
    int i, j;
    double dx = (xmax - xmin) / width;
    double dy = (ymax - ymin) / height;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            Complex z, c;
            c.real = xmin + i * dx;
            c.imag = ymin + j * dy;
            z.real = 0;
            z.imag = 0;
            int k;
            for (k = 0; k < 1000; k++) {
                z = cadd(cmul(z, z), c);
                if (cabs(z) > 2) {
                    break;
                }
            }
            putchar(" .,:;i1tfLCGWo*#"[k % 12]);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    if (argc != 7) {
        fprintf(stderr, "Usage: %s width height xmin xmax ymin ymax\n", argv[0]);
        return EXIT_FAILURE;
    }
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    double xmin = atof(argv[3]);
    double xmax = atof(argv[4]);
    double ymin = atof(argv[5]);
    double ymax = atof(argv[6]);
    mandelbrot(width, height, xmin, xmax, ymin, ymax);
    return EXIT_SUCCESS;
}