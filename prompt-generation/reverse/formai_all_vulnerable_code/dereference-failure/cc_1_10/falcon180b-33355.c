//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

int **graph;
int num_nodes;
int num_edges;
int *node_colors;
int num_colors;

void init_graph(int n) {
    num_nodes = n;
    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
    num_edges++;
}

void init_colors() {
    node_colors = (int *)malloc(num_nodes * sizeof(int));
    num_colors = 1;
    node_colors[0] = 0;
}

int is_valid_color(int c) {
    for (int i = 0; i < num_nodes; i++) {
        if (node_colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

void backtrack(int node, int color) {
    if (node == num_nodes) {
        num_colors++;
        return;
    }
    for (int i = 0; i < num_colors; i++) {
        if (is_valid_color(i)) {
            node_colors[node] = i;
            backtrack(node + 1, i);
        }
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_NODES + 2;
    init_graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u = rand() % n;
        int v = rand() % n;
        while (graph[u][v]) {
            v = rand() % n;
        }
        add_edge(u, v);
    }
    init_colors();
    backtrack(0, 0);
    printf("Number of colors used: %d\n", num_colors);
    return 0;
}