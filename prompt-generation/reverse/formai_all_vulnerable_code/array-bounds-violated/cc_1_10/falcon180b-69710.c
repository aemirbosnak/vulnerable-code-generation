//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

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

int color_graph(int v) {
    int i, j, c;
    for (i = 0; i < MAX_COLORS; i++) {
        if (colors[v]!= i) {
            colors[v] = i;
            for (j = 0; j < n; j++) {
                if (graph[v][j] == 1) {
                    c = color_graph(j);
                    if (c == -1) {
                        colors[v] = -1;
                        return -1;
                    }
                    if (c == i) {
                        colors[v] = -1;
                        return -1;
                    }
                }
            }
        }
    }
    return i;
}

int main() {
    int i, j, c;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init_graph();

    printf("Enter the edges (u v):\n");
    while (scanf("%d %d", &i, &j) == 2) {
        add_edge(i, j);
    }

    for (i = 0; i < n; i++) {
        c = color_graph(i);
        if (c == -1) {
            printf("Graph cannot be colored with %d colors\n", MAX_COLORS);
            return 0;
        }
    }

    printf("Graph can be colored with %d colors\n", MAX_COLORS);

    return 0;
}