//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int color[MAX_VERTICES];
bool graph[MAX_VERTICES][MAX_VERTICES];

bool isSafe(int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColor(int n, int m, int v) {
    if (v == n)
        return true;

    for (int i = 1; i <= m; i++) {
        if (isSafe(v, i, n)) {
            color[v] = i;

            if (graphColor(n, m, v + 1))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m, e, x, y;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &m);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges: \n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = true;
        graph[y][x] = true;
    }

    if (graphColor(n, m, 0)) {
        printf("Solution exists:\n");
        for (int i = 0; i < n; i++)
            printf("Vertex %d --> Color %d\n", i, color[i]);
        return EXIT_SUCCESS;
    }
    else {
        printf("Solution does not exist\n");
        return EXIT_FAILURE;
    }
}