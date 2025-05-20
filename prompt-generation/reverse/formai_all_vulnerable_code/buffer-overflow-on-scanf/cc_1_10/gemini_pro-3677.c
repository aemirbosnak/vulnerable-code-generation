//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MaxN 1000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point start, end;
} Path;

typedef struct {
    int n;
    Point points[MaxN];
} PointSet;

typedef struct {
    int n;
    Path paths[MaxN];
} PathSet;

// Global variables
PointSet points;
PathSet paths;

// Function prototypes
void readInput();
void findPaths();
void printPaths();

int main() {
    readInput();
    findPaths();
    printPaths();
    return 0;
}

void readInput() {
    scanf("%d", &points.n);
    for (int i = 0; i < points.n; i++) {
        scanf("%d %d", &points.points[i].x, &points.points[i].y);
    }
}

void findPaths() {
    for (int i = 0; i < points.n; i++) {
        for (int j = i + 1; j < points.n; j++) {
            Path path;
            path.start = points.points[i];
            path.end = points.points[j];
            paths.paths[paths.n++] = path;
        }
    }
}

void printPaths() {
    for (int i = 0; i < paths.n; i++) {
        printf("(%d, %d) -> (%d, %d)\n", paths.paths[i].start.x, paths.paths[i].start.y, paths.paths[i].end.x, paths.paths[i].end.y);
    }
}