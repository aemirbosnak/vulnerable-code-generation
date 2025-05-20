//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point vertices[MAX_POINTS];
    int numVertices;
} Polygon;

void readPolygon(Polygon *polygon) {
    int i, j;
    Point vertex;

    printf("Enter the number of vertices for the polygon: ");
    scanf("%d", &polygon->numVertices);

    for (i = 0; i < polygon->numVertices; i++) {
        printf("Enter the x and y coordinates of vertex %d: ", i + 1);
        scanf("%d %d", &vertex.x, &vertex.y);
        polygon->vertices[i] = vertex;
    }
}

void printPolygon(Polygon *polygon) {
    int i;

    for (i = 0; i < polygon->numVertices; i++) {
        printf("(%d, %d) ", polygon->vertices[i].x, polygon->vertices[i].y);
    }
    printf("\n");
}

int isConvex(Polygon *polygon) {
    int i, j;
    int num = polygon->numVertices;
    int count = 0;
    int sign = 0;

    for (i = 0; i < num; i++) {
        j = (i + 1) % num;
        if (sign == 0) {
            sign = (polygon->vertices[i].y - polygon->vertices[j].y) * (polygon->vertices[j].x - polygon->vertices[i].x);
        }
        if (sign > 0 && (polygon->vertices[j].y - polygon->vertices[i].y) * (polygon->vertices[i].x - polygon->vertices[(i + 1) % num].x) < 0) {
            count++;
        }
    }

    if (count == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Polygon polygon;
    int i;

    printf("Enter 1 to read a polygon from user input, or 0 to use default polygon: ");
    scanf("%d", &i);

    if (i == 1) {
        readPolygon(&polygon);
    } else {
        polygon.numVertices = 4;
        polygon.vertices[0].x = 0;
        polygon.vertices[0].y = 0;
        polygon.vertices[1].x = 0;
        polygon.vertices[1].y = 5;
        polygon.vertices[2].x = 5;
        polygon.vertices[2].y = 0;
        polygon.vertices[3].x = 5;
        polygon.vertices[3].y = 5;
    }

    if (isConvex(&polygon)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is not convex.\n");
    }

    return 0;
}