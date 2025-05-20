//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_POINTS 100
#define MAX_VERTICES 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    int numVertices;
    Point vertices[MAX_VERTICES];
} Polygon;

void readPoints(Point points[], int numPoints) {
    printf("Enter number of points: ");
    scanf("%d", &numPoints);

    for (int i = 0; i < numPoints; i++) {
        printf("Enter point %d: ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void readPolygon(Polygon polygon) {
    printf("Enter number of vertices: ");
    scanf("%d", &polygon.numVertices);

    for (int i = 0; i < polygon.numVertices; i++) {
        printf("Enter vertex %d: ", i+1);
        scanf("%d %d", &polygon.vertices[i].x, &polygon.vertices[i].y);
    }
}

void printPolygon(Polygon polygon) {
    for (int i = 0; i < polygon.numVertices; i++) {
        printf("(%d, %d) ", polygon.vertices[i].x, polygon.vertices[i].y);
    }
    printf("\n");
}

int isPointInsidePolygon(Point point, Polygon polygon) {
    int inside = 0;
    int j = polygon.numVertices - 1;

    for (int i = 0; i < polygon.numVertices; i++) {
        if ((polygon.vertices[i].y > point.y)!= (polygon.vertices[j].y > point.y) &&
            point.x < (polygon.vertices[j].x - polygon.vertices[i].x) * (point.y - polygon.vertices[i].y) / (polygon.vertices[j].y - polygon.vertices[i].y) + polygon.vertices[i].x)
            inside =!inside;

        j = i;
    }

    return inside;
}

int main() {
    Point points[MAX_POINTS];
    Polygon polygon;

    readPoints(points, MAX_POINTS);
    readPolygon(polygon);

    printf("Enter point to check: ");
    scanf("%d %d", &points[MAX_POINTS-1].x, &points[MAX_POINTS-1].y);

    if (isPointInsidePolygon(points[MAX_POINTS-1], polygon))
        printf("Point is inside polygon\n");
    else
        printf("Point is outside polygon\n");

    return 0;
}