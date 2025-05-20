//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int **graph;
int n_nodes, n_edges;
int *colors;

void init_graph() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        graph[i] = (int *) malloc(MAX_EDGES * sizeof(int));
        for (j = 0; j < MAX_EDGES; j++) {
            graph[i][j] = -1;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = v;
    graph[v][u] = u;
}

void dfs(int u, int c) {
    int v;
    colors[u] = c;
    for (v = 0; v < n_nodes; v++) {
        if (graph[u][v]!= -1 && colors[v] == WHITE) {
            dfs(v, c + 1);
        }
    }
}

int main() {
    int i, j, k;
    srand(time(NULL));
    n_nodes = rand() % MAX_NODES + 1;
    n_edges = rand() % MAX_EDGES + 1;
    printf("Number of nodes: %d\n", n_nodes);
    printf("Number of edges: %d\n", n_edges);
    init_graph();
    for (i = 0; i < n_nodes; i++) {
        colors[i] = WHITE;
    }
    for (i = 0; i < n_edges; i++) {
        j = rand() % n_nodes;
        k = rand() % n_nodes;
        while (k == j) {
            k = rand() % n_nodes;
        }
        add_edge(j, k);
    }
    for (i = 0; i < n_nodes; i++) {
        if (colors[i] == WHITE) {
            dfs(i, 0);
        }
    }
    printf("Colors:");
    for (i = 0; i < n_nodes; i++) {
        printf(" %d", colors[i]);
    }
    printf("\n");
    return 0;
}