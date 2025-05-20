//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES];
int num_nodes;
int num_edges;
int num_colors;
int *color_map;

void init_graph(int n) {
    num_nodes = n;
    num_edges = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
    num_edges++;
}

int is_connected(int node, int color) {
    if (color_map[node] == color) {
        return 1;
    }

    color_map[node] = color;

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1) {
            if (!is_connected(i, color)) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    init_graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    num_colors = rand() % MAX_COLORS + 1;
    color_map = (int *)malloc(num_nodes * sizeof(int));

    for (int i = 0; i < num_nodes; i++) {
        color_map[i] = -1;
    }

    for (int i = 0; i < num_nodes; i++) {
        if (color_map[i] == -1) {
            int color = rand() % num_colors;

            if (!is_connected(i, color)) {
                color_map[i] = color;
            }
        }
    }

    printf("Graph coloring using %d colors:\n", num_colors);

    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", color_map[i]);
    }

    free(color_map);
    return 0;
}