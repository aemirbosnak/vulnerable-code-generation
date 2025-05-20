//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100
#define MAX_E 10000

typedef struct graph {
    int V;
    int E;
    int **adj;
} graph;

void initialize_graph(graph *g, int V, int E) {
    g->V = V;
    g->E = E;
    g->adj = (int **)malloc(g->V * sizeof(int *));
    for (int i = 0; i < g->V; i++) {
        g->adj[i] = (int *)malloc(g->E * sizeof(int));
    }
}

void add_edge(graph *g, int v1, int v2) {
    g->adj[v1][g->E] = v2;
    g->adj[v2][g->E] = v1;
    g->E++;
}

int is_adjacent(graph *g, int v1, int v2) {
    return g->adj[v1][g->E] == v2 || g->adj[v2][g->E] == v1;
}

int color_vertices(graph *g, int n) {
    int *color = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        color[i] = i;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (is_adjacent(g, color[i], color[j])) {
                    int temp = color[i];
                    color[i] = color[j];
                    color[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (color[i] == color[j]) {
                return -1;
            }
        }
    }
    return n;
}

int main() {
    graph g;
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    initialize_graph(&g, V, E);
    int *adj_list = (int *)malloc(E * sizeof(int));
    for (int i = 0; i < E; i++) {
        printf("Enter the vertices connected by edge %d: ", i+1);
        scanf("%d %d", &adj_list[i], &adj_list[i+1]);
    }
    for (int i = 0; i < E; i++) {
        add_edge(&g, adj_list[i], adj_list[i+1]);
    }
    printf("Minimum number of colors required: %d\n", color_vertices(&g, V));
    return 0;
}