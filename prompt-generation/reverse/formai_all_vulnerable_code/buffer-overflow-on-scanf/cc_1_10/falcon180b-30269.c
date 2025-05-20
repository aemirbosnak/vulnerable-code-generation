//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 100
#define MAX_E 200

int V;
int E;
int adj_mat[MAX_V][MAX_V];
int color[MAX_V];

bool is_valid(int v, int c) {
    for (int u = 0; u < V; u++) {
        if (adj_mat[v][u] == 1 && color[u] == c) {
            return false;
        }
    }
    return true;
}

void color_graph(int v) {
    color[v] = 1;
    for (int u = 0; u < V; u++) {
        if (adj_mat[v][u] == 1) {
            int c = color[v] + 1;
            while (!is_valid(u, c)) {
                c++;
            }
            color[u] = c;
            color_graph(u);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj_mat[i][j]);
        }
    }

    int start_v = 0;
    color[start_v] = 1;
    color_graph(start_v);

    printf("Color of each vertex:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }

    return 0;
}