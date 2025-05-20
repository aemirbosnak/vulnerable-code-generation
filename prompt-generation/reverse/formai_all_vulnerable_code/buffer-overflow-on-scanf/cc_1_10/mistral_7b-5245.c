//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    int color;
} vertex_t;

bool is_valid_color(int graph[][10], int vertex, int color, int n) {
    for (int i = 0; i < n; i++) {
        if (i != vertex && graph[i][vertex] && graph[i][vertex] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int graph[][10], int n, int m, int *color) {
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            for (int j = 0; j < m; j++) {
                if (!is_valid_color(graph, i, j, n)) {
                    continue;
                }
                color[i] = j;
                for (int k = 0; k < n; k++) {
                    if (color[k] != -1 && graph[k][i] && graph[k][i] == j) {
                        color[i] = -1;
                        break;
                    }
                    if (k == n - 1 && graph_coloring(graph, n, m, color)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int graph[10][10], n, m;
    int color[10] = {-1};

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if (graph_coloring(graph, n, m, color)) {
        printf("Graph Colored Successfully!\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d has color %d\n", i, color[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors!\n", m);
    }

    return 0;
}