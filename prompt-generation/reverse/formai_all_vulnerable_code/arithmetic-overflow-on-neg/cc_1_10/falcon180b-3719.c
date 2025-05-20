//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define MAX_SIZE 100

typedef struct {
    int x, y;
} Point;

void init(int size, Point *p) {
    p->x = -size / 2;
    p->y = size / 2;
}

int inBounds(int x, int y, int size) {
    return -size / 2 <= x && x <= size / 2 && -size / 2 <= y && y <= size / 2;
}

void draw(int size, Point *p) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (inBounds(i, j, size)) {
                if (p->x == i && p->y == j) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int mandelbrot(double x, double y, int max_iter) {
    double real = 0, imaginary = 0;
    for (int i = 0; i < max_iter; i++) {
        double temp_real = real * real - imaginary * imaginary + x;
        imaginary = 2 * real * imaginary + y;
        real = temp_real;
        if (real * real + imaginary * imaginary > 4) {
            return i;
        }
    }
    return max_iter;
}

void fractal(int size, Point *p) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int iter = mandelbrot(p->x + (double)i / size, p->y + (double)j / size, MAX_ITER);
            if (iter == MAX_ITER) {
                printf("\033[1;31m*\033[0m");
            } else {
                printf("\033[1;32m%d\033[0m", iter);
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the fractal (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);
    Point p;
    init(size, &p);
    if (size > 1) {
        fractal(size, &p);
    }
    draw(size, &p);
    return 0;
}