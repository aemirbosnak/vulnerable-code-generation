//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_EDGES 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int v1;
    int v2;
    int weight;
} Edge;

int num_points, num_edges;
Point points[MAX_POINTS];
Edge edges[MAX_EDGES];

void read_points() {
    printf("Enter number of points: ");
    scanf("%d", &num_points);
    for (int i = 0; i < num_points; i++) {
        printf("Enter coordinates of point %d: ", i+1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void read_edges() {
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    for (int i = 0; i < num_edges; i++) {
        printf("Enter endpoints and weight of edge %d: ", i+1);
        scanf("%d %d %d", &edges[i].v1, &edges[i].v2, &edges[i].weight);
    }
}

void kruskal_algorithm() {
    int parent[MAX_POINTS];
    for (int i = 0; i < num_points; i++) {
        parent[i] = i;
    }

    int num_components = num_points;
    int component[MAX_POINTS];
    for (int i = 0; i < num_points; i++) {
        component[i] = -1;
    }

    int num_edges_added = 0;
    for (int i = 0; i < num_edges; i++) {
        int root1 = find_parent(parent, edges[i].v1);
        int root2 = find_parent(parent, edges[i].v2);

        if (root1!= root2) {
            parent[root1] = root2;
            num_components--;
            component[edges[i].v1] = root2;
            component[edges[i].v2] = root2;
            num_edges_added++;
        }
    }

    printf("Number of components: %d\n", num_components);
    printf("Minimum spanning tree weight: %d\n", num_edges_added);
}

int find_parent(int parent[], int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    } else {
        return parent[vertex] = find_parent(parent, parent[vertex]);
    }
}

int main() {
    read_points();
    read_edges();
    kruskal_algorithm();
    return 0;
}