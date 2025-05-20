//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_EDGES 2000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point a, b;
    int index;
} Edge;

Edge edges[MAX_EDGES];
int num_edges = 0;

void add_edge(int x1, int y1, int x2, int y2) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Too many edges\n");
        exit(1);
    }

    edges[num_edges].a.x = x1;
    edges[num_edges].a.y = y1;
    edges[num_edges].b.x = x2;
    edges[num_edges].b.y = y2;
    edges[num_edges].index = num_edges;
    num_edges++;
}

void add_point(int x, int y) {
    // Do nothing for now
}

void sort_edges() {
    // Do nothing for now
}

int main() {
    int num_points;
    scanf("%d", &num_points);

    for (int i = 0; i < num_points; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        add_edge(x1, y1, x2, y2);
    }

    sort_edges();

    // Do nothing for now

    return 0;
}