//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POINTS 100
#define MAX_EDGES 1000

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Edge {
    Point start;
    Point end;
    struct Edge* next;
} Edge;

Point points[MAX_POINTS];
Edge edges[MAX_EDGES];

int main() {
    int i, j, k, numPoints, numEdges;

    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (i = 0; i < numPoints; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    for (i = 0; i < numEdges; i++) {
        edges[i].start.x = rand() % numPoints;
        edges[i].start.y = rand() % numPoints;
        edges[i].end.x = rand() % numPoints;
        edges[i].end.y = rand() % numPoints;
        edges[i].next = NULL;
    }

    for (i = 0; i < numPoints; i++) {
        printf("Point %d: (%d, %d)\n", i, points[i].x, points[i].y);
    }

    for (i = 0; i < numEdges; i++) {
        printf("Edge %d: (%d, %d) - (%d, %d)\n", i, edges[i].start.x, edges[i].start.y, edges[i].end.x, edges[i].end.y);
    }

    return 0;
}