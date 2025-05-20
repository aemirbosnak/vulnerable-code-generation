//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100

typedef struct {
    int x, y;
} Point;

void draw_point(Point p) {
    printf("*");
}

Point generate_fractal(int x, int y, int iterations) {
    Point result = {0, 0};
    int i;
    for (i = 0; i < iterations; i++) {
        double x_new = x + pow(result.x, 2) - pow(result.y, 2) + 1;
        double y_new = 2 * result.x * result.y + y - 1;
        result.x = x_new;
        result.y = y_new;
    }
    return result;
}

void generate_fractal_image(int width, int height, int x_min, int y_min, int x_max, int y_max, int max_iterations) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int x = x_min + j;
            int y = y_min + i;
            int iterations = iterate_fractal(x, y, max_iterations);
            draw_point(generate_fractal(x, y, iterations));
        }
    }
}

int iterate_fractal(int x, int y, int max_iterations) {
    int iterations = 0;
    Point p = {0, 0};
    while (iterations < max_iterations && abs(p.x) < 2 && abs(p.y) < 2) {
        p = generate_fractal(x, y, iterations);
        iterations++;
    }
    return iterations;
}

int main() {
    int width, height, max_iterations;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iterations);

    generate_fractal_image(width, height, -2, -2, 1, 1, max_iterations);

    return 0;
}