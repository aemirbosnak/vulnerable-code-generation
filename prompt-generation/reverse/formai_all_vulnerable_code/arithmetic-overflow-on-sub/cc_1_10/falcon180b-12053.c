//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_POINTS 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int numPoints;
    Point points[MAX_POINTS];
} Polygon;

void readPoints(Polygon *poly) {
    printf("Enter the number of points in the polygon: ");
    scanf("%d", &poly->numPoints);

    for (int i = 0; i < poly->numPoints; i++) {
        printf("Enter the coordinates for point %d: ", i + 1);
        scanf("%d %d", &poly->points[i].x, &poly->points[i].y);
    }
}

void printPolygon(Polygon *poly) {
    printf("Polygon with %d points:\n", poly->numPoints);

    for (int i = 0; i < poly->numPoints; i++) {
        printf("Point %d: (%d, %d)\n", i + 1, poly->points[i].x, poly->points[i].y);
    }
}

void calculateArea(Polygon *poly) {
    int area = 0;

    for (int i = 0; i < poly->numPoints - 1; i++) {
        int x1 = poly->points[i].x;
        int y1 = poly->points[i].y;
        int x2 = poly->points[i + 1].x;
        int y2 = poly->points[i + 1].y;

        int dx = x2 - x1;
        int dy = y2 - y1;

        area += dx * dy;
    }

    printf("The area of the polygon is %d\n", abs(area / 2));
}

void calculatePerimeter(Polygon *poly) {
    int perimeter = 0;

    for (int i = 0; i < poly->numPoints - 1; i++) {
        int x1 = poly->points[i].x;
        int y1 = poly->points[i].y;
        int x2 = poly->points[i + 1].x;
        int y2 = poly->points[i + 1].y;

        int dx = x2 - x1;
        int dy = y2 - y1;

        perimeter += sqrt(pow(dx, 2) + pow(dy, 2));
    }

    printf("The perimeter of the polygon is %d\n", perimeter);
}

int main() {
    Polygon poly;

    readPoints(&poly);
    printPolygon(&poly);

    calculateArea(&poly);
    calculatePerimeter(&poly);

    return 0;
}