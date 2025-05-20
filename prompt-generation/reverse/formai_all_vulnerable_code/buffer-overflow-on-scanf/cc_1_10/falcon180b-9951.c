//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int colors[MAX_VERTICES];

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int is_connected(int u, int c) {
    int i;
    colors[u] = c;
    for (i = 0; i < n; i++) {
        if (graph[u][i] == 1 && colors[i] == 0) {
            if (!is_connected(i, c + 1)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph();
    printf("Enter the edges: ");
    while (scanf("%d%d", &i, &j) == 2) {
        add_edge(i, j);
    }
    int max_color = 0;
    for (i = 0; i < n; i++) {
        if (colors[i] == 0) {
            if (!is_connected(i, 1)) {
                printf("Graph is not connected.\n");
                return 0;
            }
            max_color = MAX_COLORS - 1;
        }
    }
    printf("Graph is connected and can be colored with %d colors.\n", max_color + 1);
    return 0;
}