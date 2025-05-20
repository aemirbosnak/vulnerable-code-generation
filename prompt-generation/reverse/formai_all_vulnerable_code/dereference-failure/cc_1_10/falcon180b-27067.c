//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define MAX_WIDTH 800
#define MAX_HEIGHT 600
#define MAX_ZOOM 10

typedef struct {
    int x;
    int y;
} Point;

void draw_fractal(int width, int height, Point *points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        int x = points[i].x;
        int y = points[i].y;
        if (x >= 0 && x < width && y >= 0 && y < height) {
            printf("*");
        }
    }
}

int main() {
    int num_iterations = 0;
    int num_points = 0;
    Point *points = NULL;
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int zoom = 1;

    while (num_iterations < MAX_ITERATIONS) {
        num_points = 0;
        points = (Point *) realloc(points, sizeof(Point) * num_points);
        double x = -2.0;
        double y = -1.5;
        double x_prev = 0.0;
        double y_prev = 0.0;
        while (num_points < MAX_WIDTH * MAX_HEIGHT) {
            double x_next = x * x + y;
            double y_next = 2.0 * x * y + 1.0;
            x = x_next;
            y = y_next;
            if (x * x + y * y > 4.0) {
                break;
            }
            if (num_points >= MAX_WIDTH * MAX_HEIGHT / zoom) {
                break;
            }
            Point point = {
               .x = (int) (x * width / zoom + width / 2),
               .y = (int) (y * height / zoom + height / 2)
            };
            points[num_points++] = point;
        }
        draw_fractal(width, height, points, num_points);
        num_iterations++;
        printf("Iteration %d\n", num_iterations);
        if (num_iterations % 10 == 0) {
            zoom++;
            width /= zoom;
            height /= zoom;
        }
    }

    return 0;
}