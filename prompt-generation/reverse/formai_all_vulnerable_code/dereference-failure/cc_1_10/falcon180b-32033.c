//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

Point *generatePoints(int numPoints) {
    Point *points = (Point *)malloc(numPoints * sizeof(Point));
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
    }
    return points;
}

void drawPoints(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

void shiftPoints(Point *points, int numPoints, int dx, int dy) {
    for (int i = 0; i < numPoints; i++) {
        points[i].x += dx;
        points[i].y += dy;
    }
}

void rotatePoints(Point *points, int numPoints, double angle) {
    double radians = angle * M_PI / 180.0;
    int cx = (int)cos(radians);
    int cy = (int)sin(radians);
    for (int i = 0; i < numPoints; i++) {
        int x = points[i].x - 500;
        int y = points[i].y - 500;
        points[i].x = 500 + x * cx - y * cy;
        points[i].y = 500 + x * cy + y * cx;
    }
}

void scalePoints(Point *points, int numPoints, double factor) {
    for (int i = 0; i < numPoints; i++) {
        points[i].x *= factor;
        points[i].y *= factor;
    }
}

int main() {
    srand(time(NULL));
    Point *points = generatePoints(10);
    drawPoints(points, 10);
    shiftPoints(points, 10, 50, 50);
    drawPoints(points, 10);
    rotatePoints(points, 10, 45);
    drawPoints(points, 10);
    scalePoints(points, 10, 2.0);
    drawPoints(points, 10);
    free(points);
    return 0;
}