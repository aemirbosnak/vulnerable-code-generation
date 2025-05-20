//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point vertices[MAX_VERTICES];
    int numVertices;
} Polygon;

void readPolygon(Polygon* polygon) {
    printf("Enter number of vertices: ");
    scanf("%d", &polygon->numVertices);
    for (int i = 0; i < polygon->numVertices; i++) {
        printf("Enter vertex %d coordinates (x y): ", i + 1);
        scanf("%d %d", &polygon->vertices[i].x, &polygon->vertices[i].y);
    }
}

void printPolygon(Polygon* polygon) {
    for (int i = 0; i < polygon->numVertices; i++) {
        printf("(%d, %d) ", polygon->vertices[i].x, polygon->vertices[i].y);
    }
    printf("\n");
}

int isConvex(Polygon* polygon) {
    int sum = 0;
    for (int i = 0; i < polygon->numVertices; i++) {
        int j = (i + 1) % polygon->numVertices;
        sum += (polygon->vertices[j].x - polygon->vertices[i].x) * (polygon->vertices[j].y - polygon->vertices[i].y);
    }
    return sum > 0;
}

int isConcave(Polygon* polygon) {
    return!isConvex(polygon);
}

void main() {
    Polygon polygon;
    readPolygon(&polygon);
    if (isConvex(&polygon)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is concave.\n");
    }
    printPolygon(&polygon);
}