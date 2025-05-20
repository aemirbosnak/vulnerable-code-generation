//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 1000

typedef struct complex {
    double real;
    double imag;
} Complex;

Complex add_complex(Complex a, Complex b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;
    return sum;
}

Complex multiply_complex(Complex a, Complex b) {
    Complex product;
    product.real = a.real * b.real - a.imag * b.imag;
    product.imag = a.real * b.imag + a.imag * b.real;
    return product;
}

void fractal_generation(Complex c) {
    Complex z;
    z.real = z.imag = 0.0;
    int i;
    for (i = 0; i < NUM_POINTS; i++) {
        z = add_complex(multiply_complex(z, z), c);
        if (z.real * z.real + z.imag * z.imag > 4.0) {
            printf("*");
        } else {
            printf(" ");
        }
    }
}

int main() {
    Complex c;
    int i, j;

    for (i = 0; i < 25; i++) {
        for (j = 0; j < 50; j++) {
            c.real = j * 0.08 - 2.0;
            c.imag = i * 0.1 - 1.0;
            fractal_generation(c);
        }
        printf("\n");
    }

    return 0;
}