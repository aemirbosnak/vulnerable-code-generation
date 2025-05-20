//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: safe
/*
 * A safe Fractal Generation program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 1000
#define MAX_DIM 1000

struct Complex {
    double x;
    double y;
};

void generate_fractal(double x0, double y0, double x1, double y1, int n, int dim) {
    struct Complex c1 = {x0, y0};
    struct Complex c2 = {x1, y1};
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            struct Complex z = {(double)i / dim, (double)j / dim};
            int iter = 0;

            while (iter < MAX_ITER && abs(z.x * z.x - z.y * z.y) < 4) {
                struct Complex new_z = {z.x * z.x - z.y * z.y, 2 * z.x * z.y};
                z = new_z;
                iter++;
            }

            if (iter == MAX_ITER) {
                printf("x");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    double x0, y0, x1, y1;
    int n, dim;

    printf("Enter the bounds for the fractal (x0, y0, x1, y1): ");
    scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Enter the dimensions of the fractal (width, height): ");
    scanf("%d %d", &dim, &dim);

    generate_fractal(x0, y0, x1, y1, n, dim);

    return 0;
}