//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int size;
    int capacity;
} Polygon;

Polygon *createPolygon(int capacity) {
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    polygon->points = (Point *)malloc(sizeof(Point) * capacity);
    polygon->size = 0;
    polygon->capacity = capacity;
    return polygon;
}

void addPoint(Polygon *polygon, double x, double y) {
    if (polygon->size >= polygon->capacity) {
        polygon->capacity *= 2;
        polygon->points = (Point *)realloc(polygon->points, sizeof(Point) * polygon->capacity);
    }
    polygon->points[polygon->size].x = x;
    polygon->points[polygon->size].y = y;
    polygon->size++;
}

double calculateArea(Polygon *polygon) {
    double area = 0;
    for (int i = 0; i < polygon->size; i++) {
        int next = (i + 1) % polygon->size; // wrap around
        area += (polygon->points[i].x * polygon->points[next].y);
        area -= (polygon->points[next].x * polygon->points[i].y);
    }
    return fabs(area) / 2.0;
}

void destroyPolygon(Polygon *polygon) {
    free(polygon->points);
    free(polygon);
}

int main() {
    int capacity = 4; // starting capacity for polygon
    Polygon *polygon = createPolygon(capacity);
    double x, y;

    printf("Enter points for the polygon (x y pairs), end with '-1 -1':\n");

    while (1) {
        scanf("%lf %lf", &x, &y);
        if (x == -1 && y == -1) {
            break;
        }
        addPoint(polygon, x, y);
    }

    double area = calculateArea(polygon);
    printf("The area of the polygon is: %.2f\n", area);

    destroyPolygon(polygon);
    return 0;
}