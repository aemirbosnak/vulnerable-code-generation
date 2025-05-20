//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 200

typedef struct {
    int v;
    int w;
    int weight;
} Edge;

Edge graph[MAX_E];
int V, E;
int parent[MAX_V];

void init() {
    V = 0;
    E = 0;
    memset(parent, -1, sizeof(parent));
}

void addEdge(int u, int v, int w) {
    Edge e1 = {u, v, w};
    Edge e2 = {v, u, w};
    graph[E++] = e1;
    graph[E++] = e2;
}

void kruskal() {
    int i, j, u, v;
    Edge e;
    int count = 0;
    int min_weight = 0;

    for (i = 0; i < E; i++) {
        e = graph[i];
        u = e.v;
        v = e.w;
        min_weight = e.weight;

        for (j = 0; j < E; j++) {
            if (graph[j].v == u && graph[j].w == v && graph[j].weight < min_weight) {
                min_weight = graph[j].weight;
            }
        }

        if (parent[u]!= parent[v]) {
            parent[v] = u;
            count++;
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < E; i++) {
        e = graph[i];
        u = e.v;
        v = e.w;

        if (parent[v] == u) {
            printf("%d - %d (%d)\n", u, v, e.weight);
        }
    }

    printf("\nTotal weight: %d\n", count);
}

int find(int v) {
    if (parent[v] == -1) {
        return v;
    }

    return find(parent[v]);
}

int main() {
    int i, u, v, w;

    init();

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    kruskal();

    return 0;
}