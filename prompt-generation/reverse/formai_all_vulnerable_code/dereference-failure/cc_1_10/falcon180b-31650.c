//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int width = 1000, height = 1000;
    int numPoints = 1000;
    Point* points = malloc(numPoints * sizeof(Point));
    for (int i = 0; i < numPoints; i++) {
        points[i].x = rand() % width;
        points[i].y = rand() % height;
    }
    int numIterations = 1000;
    for (int i = 0; i < numIterations; i++) {
        for (int j = 0; j < numPoints; j++) {
            Point* p1 = &points[j];
            Point* p2 = &points[(j+1)%numPoints];
            double dx = p1->x - p2->x;
            double dy = p1->y - p2->y;
            double dist = sqrt(dx*dx + dy*dy);
            if (dist < 50) {
                double angle = atan2(dy, dx);
                double forceX = cos(angle) * (50 - dist) * 0.1;
                double forceY = sin(angle) * (50 - dist) * 0.1;
                p1->x += forceX;
                p1->y += forceY;
                p2->x -= forceX;
                p2->y -= forceY;
            }
        }
        for (int j = 0; j < numPoints; j++) {
            Point* p1 = &points[j];
            Point* p2 = &points[(j+1)%numPoints];
            double dx = p1->x - p2->x;
            double dy = p1->y - p2->y;
            double dist = sqrt(dx*dx + dy*dy);
            if (dist < 50) {
                double angle = atan2(dy, dx);
                double forceX = cos(angle) * (50 - dist) * 0.1;
                double forceY = sin(angle) * (50 - dist) * 0.1;
                p1->x += forceX;
                p1->y += forceY;
                p2->x -= forceX;
                p2->y -= forceY;
            }
        }
    }
    for (int i = 0; i < numPoints; i++) {
        printf("%.0f %.0f\n", points[i].x, points[i].y);
    }
    free(points);
    return 0;
}