//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI M_PI

typedef struct {
    double x, y;
} Point;

Point midPoint(Point p1, Point p2) {
    Point result;
    result.x = (p1.x + p2.x) / 2.0;
    result.y = (p1.y + p2.y) / 2.0;
    return result;
}

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

void drawLine(Point p1, Point p2) {
    printf("Line from (%lf, %lf) to (%lf, %lf)\n", p1.x, p1.y, p2.x, p2.y);
}

void starPolygon(Point center, int numPoints, double maxDeviation) {
    double totalAngle = 2.0 * PI / numPoints;
    Point vertices[numPoints];
    int i;

    vertices[0].x = center.x + cos(0.0) * 50.0;
    vertices[0].y = center.y + sin(0.0) * 50.0;

    for (i = 1; i < numPoints; i++) {
        vertices[i].x = center.x + cos(i * totalAngle) * 50.0;
        vertices[i].y = center.y + sin(i * totalAngle) * 50.0;
    }

    for (i = 0; i < numPoints; i++) {
        Point next = i == numPoints - 1 ? vertices[0] : vertices[i + 1];
        if (dist(vertices[i], next) > 2.0 * cos(maxDeviation / 2.0) * 50.0) {
            Point mid = midPoint(vertices[i], next);
            double angle = atan2(next.y - vertices[i].y, next.x - vertices[i].x) * 180.0 / PI;
            starPolygon(mid, numPoints, maxDeviation);
            drawLine(vertices[i], mid);
            vertices[i] = mid;
        }
    }
}

int main() {
    int numPoints, i;
    double maxDeviation;

    printf("Enter the number of points: ");
    scanf("%d", &numPoints);
    printf("Enter the maximum deviation angle (degrees): ");
    scanf("%lf", &maxDeviation);

    Point center = {100.0, 100.0};
    starPolygon(center, numPoints, maxDeviation);

    return 0;
}