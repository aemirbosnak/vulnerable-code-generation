//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_POINTS 5000
#define NUM_ITERATIONS 100

typedef struct {
    int x;
    int y;
} Point;

void initialize(Point* points, int num_points) {
    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % WIDTH;
        points[i].y = rand() % HEIGHT;
    }
}

void mandelbrot(Point* points, int num_points, int num_iterations) {
    for (int i = 0; i < num_points; i++) {
        double x = (double)points[i].x / WIDTH;
        double y = (double)points[i].y / HEIGHT;
        double real = 0, imag = 0;
        int iterations = 0;
        while (iterations < num_iterations && pow(real*real + imag*imag, 2) < 4) {
            double temp_real = real*real - imag*imag + x;
            imag = 2*real*imag + y;
            real = temp_real;
            iterations++;
        }
        points[i].x = iterations % 8 * 32;
        points[i].y = iterations % 16 * 32;
    }
}

void draw(Point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        printf("%d,%d ", points[i].x, points[i].y);
    }
}

int main() {
    Point* points = malloc(NUM_POINTS * sizeof(Point));
    initialize(points, NUM_POINTS);
    mandelbrot(points, NUM_POINTS, NUM_ITERATIONS);
    draw(points, NUM_POINTS);
    free(points);
    return 0;
}