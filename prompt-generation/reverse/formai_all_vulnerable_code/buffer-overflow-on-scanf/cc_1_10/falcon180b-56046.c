//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES];
int n;
int m;
int colors[MAX_NODES];
int color_count;

void init_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

bool is_connected(int u, int v) {
    if (u == v) {
        return true;
    }
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[u][i] && graph[i][v]) {
            return true;
        }
    }
    return false;
}

bool color(int node, int color) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && colors[i] == color) {
            return false;
        }
    }
    colors[node] = color;
    return true;
}

bool graph_coloring() {
    int i = 0;
    while (i < n) {
        if (!color(i, i % MAX_COLORS)) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the nodes for edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    printf("Enter the maximum number of colors: ");
    scanf("%d", &color_count);
    if (graph_coloring()) {
        printf("The graph can be colored with %d colors.\n", color_count);
    } else {
        printf("The graph cannot be colored with %d colors.\n", color_count);
    }
    return 0;
}