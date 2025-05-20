//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_V 1000
#define MAX_E 2000

typedef struct {
    int v;
    int w;
    double weight;
} Edge;

int V, E;
Edge *graph;
int *visited;
int *parent;

void init() {
    V = 0;
    E = 0;
    graph = (Edge *)malloc(MAX_V * sizeof(Edge));
    visited = (int *)malloc(MAX_V * sizeof(int));
    parent = (int *)malloc(MAX_V * sizeof(int));
}

void add_edge(int u, int v, double w) {
    graph[E].v = u;
    graph[E].w = v;
    graph[E].weight = w;
    E++;
}

void dijkstra(int start) {
    int i, j, k, u, v;
    double min_dist, dist;

    for (i = 0; i < V; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    visited[start] = 1;
    dist = 0;

    for (i = 1; i < V; i++) {
        min_dist = INFINITY;
        u = -1;

        for (j = 0; j < V; j++) {
            if (visited[j] == 1 && graph[j].weight < min_dist) {
                min_dist = graph[j].weight;
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < V; j++) {
            k = u ^ j;

            if (graph[k].weight > 0 &&!visited[j]) {
                dist = graph[k].weight + dist;

                if (dist < graph[j].weight) {
                    graph[j].weight = dist;
                    parent[j] = u;
                }
            }
        }
    }
}

int main() {
    init();

    add_edge(0, 1, 1.0);
    add_edge(1, 2, 2.0);
    add_edge(2, 3, 3.0);
    add_edge(3, 4, 4.0);

    dijkstra(0);

    printf("Vertex\tParent\tDistance\n");

    for (int i = 0; i < V; i++) {
        if (parent[i]!= -1) {
            printf("%d\t%d\t%.2f\n", i, parent[i], graph[i].weight);
        }
    }

    return 0;
}