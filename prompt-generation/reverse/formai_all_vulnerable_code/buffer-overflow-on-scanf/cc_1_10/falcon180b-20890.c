//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define PI 3.14159265358979323846

void drawFractal(int x, int y, int w, int h, int maxIter) {
    int i, j, iter;
    double real, imag, zx, zy, zr, zi;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            zx = j * (3.0 / w) - 2.0;
            zy = i * (2.0 / h) - 1.0;

            zr = 0;
            zi = 0;
            iter = 0;

            while (iter < maxIter && zr * zr + zi * zi < 4.0) {
                zr = zr * zr - zi * zi + zx;
                zi = 2 * zr * zi + zy;
                iter++;
            }

            if (iter == maxIter) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x, y, w, h, maxIter;

    printf("Enter the x-coordinate of the top-left corner: ");
    scanf("%d", &x);

    printf("Enter the y-coordinate of the top-left corner: ");
    scanf("%d", &y);

    printf("Enter the width of the fractal: ");
    scanf("%d", &w);

    printf("Enter the height of the fractal: ");
    scanf("%d", &h);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIter);

    if (maxIter < 1 || maxIter > MAX_ITER) {
        printf("Invalid maximum number of iterations.\n");
        return 1;
    }

    drawFractal(x, y, w, h, maxIter);

    return 0;
}