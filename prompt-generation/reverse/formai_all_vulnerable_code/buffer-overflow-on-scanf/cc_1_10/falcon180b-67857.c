//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define ESCAPE_TIME 4.0

void drawFractal(int x, int y, int maxIterations) {
    int iterations;
    double real = x / 400.0;
    double imag = y / 400.0;
    double zreal = 0.0;
    double zimag = 0.0;

    for (iterations = 0; iterations < maxIterations; ++iterations) {
        double tempReal = zreal * zreal - zimag * zimag + real;
        double tempImag = 2.0 * zreal * zimag + imag;
        zreal = tempReal;
        zimag = tempImag;

        if (zreal * zreal + zimag * zimag > ESCAPE_TIME) {
            break;
        }
    }

    if (iterations == maxIterations) {
        printf("*");
    } else {
        printf(" ");
    }
}

int main() {
    int maxX, maxY;
    int x, y;

    printf("Enter the maximum X value: ");
    scanf("%d", &maxX);
    printf("Enter the maximum Y value: ");
    scanf("%d", &maxY);

    for (y = 0; y < maxY; ++y) {
        for (x = 0; x < maxX; ++x) {
            drawFractal(x, y, MAX_ITERATIONS);
        }
        printf("\n");
    }

    return 0;
}