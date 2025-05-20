//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define MAX_COLOR 7

int graph[V][V] = { { 0, 2, 0, 0, 0, 0, 0, 0, 0 },
                    { 2, 0, 3, 0, 0, 0, 0, 0, 0 },
                    { 0, 3, 0, 4, 0, 0, 0, 0, 0 },
                    { 0, 0, 4, 0, 1, 1, 0, 0, 0 },
                    { 0, 0, 0, 1, 0, 3, 0, 0, 0 },
                    { 0, 0, 0, 1, 3, 0, 5, 0, 0 },
                    { 0, 0, 0, 0, 0, 5, 0, 6, 0 },
                    { 0, 0, 0, 0, 0, 0, 6, 0, 5 },
                    { 0, 0, 0, 0, 0, 0, 0, 5, 0 } };

int n, m, i, j, k, u, v, color[V];

void initialize() {
    for (i = 0; i < V; i++) {
        color[i] = -1;
    }
}

int is_valid(int c) {
    for (i = 0; i < V; i++) {
        if (graph[i][c] == 1) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int c) {
    int k = 0;
    for (i = 0; i < V; i++) {
        if (graph[c][i] == 1) {
            color[i] = k;
            k++;
        }
    }
}

int main() {
    int i, j, max_color = 0;

    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d %d", &n, &m);

    initialize();

    printf("Enter the edges of the graph:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            color_graph(i);
            max_color++;
        }
    }

    printf("The chromatic number of the graph is %d\n", max_color);

    return 0;
}