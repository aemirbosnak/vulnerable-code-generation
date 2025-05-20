//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int n, m, k;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColor(int v) {
    if (v == n) {
        return true;
    }
    for (int c = 1; c <= k; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColor(v + 1)) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the number of colors: ");
    scanf("%d", &k);

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if (graphColor(0)) {
        printf("The minimum number of colors required to color the graph is %d\n", k);
        printf("The color assignment of each vertex is:\n");
        for (int i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}