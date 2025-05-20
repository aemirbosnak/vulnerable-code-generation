//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 1000000
#define MAX_ITERATIONS 1000

typedef struct {
    double x, y;
} Point;

int generateFractal(double x1, double y1, double x2, double y2, int iterations) {
    Point p1 = {x1, y1};
    Point p2 = {x2, y2};
    Point p3 = {0, 0};
    Point p = p1;
    int count = 0;

    while (count < iterations) {
        double tempX = (p.x + p.y) / 2 + (p2.y - p1.y) / 2;
        double tempY = (-p.x + p.y) / 2 + (p1.x - p2.x) / 2;
        p.x = tempX;
        p.y = tempY;
        count++;
    }

    return count;
}

int main() {
    int iterations;
    double x1, y1, x2, y2;

    printf("Enter the coordinates of the first point: ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point: ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    Point points[MAX_POINTS];
    int numPoints = 0;

    numPoints = generateFractal(x1, y1, x2, y2, iterations);

    printf("Generated %d points\n", numPoints);

    return 0;
}