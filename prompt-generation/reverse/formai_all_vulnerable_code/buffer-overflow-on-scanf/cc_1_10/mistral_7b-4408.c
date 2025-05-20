//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_COLOR 7

bool graph_coloring(int graph[MAX_VERTICES][MAX_VERTICES], int n, int m, int vertex, int color[]) {
    if (vertex >= n) {
        return true;
    }

    for (int i = 0; i < m; i++) {
        if (graph[vertex][i] && color[i] == color[vertex]) {
            return false;
        }
    }

    for (int i = 0; i < m; i++) {
        color[i] = (color[i] + 1) % MAX_COLOR;
        if (graph_coloring(graph, n, m, vertex + 1, color)) {
            return true;
        }
        color[i] = (color[i] - 1 + MAX_COLOR) % MAX_COLOR;
    }

    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int color[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        color[i] = 0;
    }

    if (graph_coloring(graph, n, m, 0, color)) {
        for (int i = 0; i < n; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
    } else {
        printf("Graph cannot be colored!\n");
    }

    return 0;
}