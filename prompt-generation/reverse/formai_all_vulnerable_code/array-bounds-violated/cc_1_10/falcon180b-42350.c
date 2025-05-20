//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 50
#define MAX_E 100

int V, E;
int G[MAX_V][MAX_V];
int color[MAX_V];

void init_graph(int v, int e) {
    V = v;
    E = e;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            G[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    G[u][v] = 1;
    G[v][u] = 1;
}

void dfs_color(int v, int c) {
    color[v] = c;

    for (int i = 0; i < V; i++) {
        if (G[v][i] && color[i] == -1) {
            dfs_color(i, c + 1);
        }
    }
}

int main() {
    int v, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    init_graph(v, e);

    printf("Enter the edges:\n");

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            dfs_color(i, 1);
        }
    }

    printf("Vertex Color:\n");

    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }

    return 0;
}