//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES];
int n;
int colors[MAX_NODES];
int num_colors;

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

bool is_valid_color(int color, int node) {
    int i;
    for (i = 0; i < node; i++) {
        if (colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(int node) {
    int i;
    if (node == n) {
        num_colors = 0;
        for (i = 0; i < n; i++) {
            if (colors[i]!= 0) {
                num_colors++;
            }
        }
        if (num_colors == MAX_COLORS) {
            return false;
        }
        return true;
    }
    for (i = 1; i <= MAX_COLORS; i++) {
        if (is_valid_color(i, node)) {
            colors[node] = i;
            if (color_graph(node + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    init_graph();

    printf("Enter the edges (u v):\n");
    while (scanf("%d %d", &i, &j) == 2) {
        add_edge(i, j);
    }

    int max_colors = 0;
    for (i = 0; i < n; i++) {
        colors[i] = 0;
        if (color_graph(i + 1)) {
            max_colors++;
        }
    }

    printf("The maximum number of colors needed is %d\n", max_colors);

    return 0;
}