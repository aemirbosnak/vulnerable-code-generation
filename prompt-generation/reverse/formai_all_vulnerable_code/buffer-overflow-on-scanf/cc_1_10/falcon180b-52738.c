//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define PI 3.14159265358979323846

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *vertices;
    int n;
} Polygon;

Polygon createPolygon(int n) {
    Polygon polygon = {
       .vertices = (Point *)malloc(n * sizeof(Point)),
       .n = n
    };
    for (int i = 0; i < n; i++) {
        polygon.vertices[i].x = rand() % MAX;
        polygon.vertices[i].y = rand() % MAX;
    }
    return polygon;
}

void printPolygon(Polygon polygon) {
    for (int i = 0; i < polygon.n; i++) {
        printf("(%d,%d) ", polygon.vertices[i].x, polygon.vertices[i].y);
    }
    printf("\n");
}

int isConvex(Polygon polygon) {
    int n = polygon.n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        Point p1 = polygon.vertices[i];
        Point p2 = polygon.vertices[j];
        Point p3 = {p1.x + (p2.x - p1.x) / 2, p1.y + (p2.y - p1.y) / 2};
        int crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
        if (crossProduct < 0) {
            count++;
        }
    }
    return count % n == 0;
}

int main() {
    int n;
    printf("Enter the number of sides of the polygon: ");
    scanf("%d", &n);
    Polygon polygon = createPolygon(n);
    printf("The polygon is %s.\n", isConvex(polygon)? "convex" : "not convex");
    printPolygon(polygon);
    return 0;
}