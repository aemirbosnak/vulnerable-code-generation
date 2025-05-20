//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VERTS 1000
#define MAX_EDGES 2000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point a, b;
} Edge;

int num_verts, num_edges;
Edge edges[MAX_EDGES];

void add_edge(int a, int b) {
    Edge e = { {a, b}, {b, a} };
    edges[num_edges++] = e;
}

void kruskal() {
    int parent[MAX_VERTS];
    int rank[MAX_VERTS];

    for (int i = 0; i < num_verts; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int num_sets = num_verts;

    for (int i = 0; i < num_edges; i++) {
        int u = find_parent(parent, edges[i].a.x, edges[i].a.y);
        int v = find_parent(parent, edges[i].b.x, edges[i].b.y);

        if (u!= v) {
            add_edge(u, v);
            num_sets--;
        }
    }

    printf("Minimum Spanning Tree has %d edges\n", num_sets - 1);
}

int find_parent(int parent[], int x, int y) {
    if (parent[x*num_verts + y]!= x*num_verts + y)
        parent[x*num_verts + y] = find_parent(parent, parent[x*num_verts + y], 0);

    return parent[x*num_verts + y];
}

int main() {
    int x, y;

    printf("Enter number of vertices: ");
    scanf("%d", &num_verts);

    for (int i = 0; i < num_verts; i++) {
        printf("Enter coordinates for vertex %d: ", i+1);
        scanf("%d%d", &x, &y);
        add_edge(i, i);
    }

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        printf("Enter indices of vertices for edge %d: ", i+1);
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }

    kruskal();

    return 0;
}