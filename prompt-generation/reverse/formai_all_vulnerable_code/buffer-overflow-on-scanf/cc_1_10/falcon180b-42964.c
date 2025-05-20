//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 100
#define MAX_COLOR 100

int V, E;
int adj_matrix[MAX_V][MAX_V];
int color[MAX_V];
int color_count;

void init_graph(int v, int e) {
    V = v;
    E = e;
    color_count = 0;
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }
}

void add_edge(int u, int v) {
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

bool is_safe(int v, int c, int u) {
    if (color[u] == c) return false;
    for (int i = 0; i < V; i++) {
        if (adj_matrix[u][i] && color[i] == c) return false;
    }
    return true;
}

void color_graph(int v) {
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            color[i] = color_count++;
            for (int j = 0; j < V; j++) {
                if (adj_matrix[i][j] && color[j] == -1) {
                    color[j] = color[i];
                }
            }
        }
    }
}

int main() {
    int v, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &v, &e);
    init_graph(v, e);
    printf("Enter the edges: ");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    color_graph(v);
    for (int i = 0; i < V; i++) {
        printf("%d: %d\n", i, color[i]);
    }
    return 0;
}