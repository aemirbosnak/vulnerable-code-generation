//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int adj[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

int is_safe(int v, int c, int n) {
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

void graph_coloring(int v, int n, int k) {
    if (v == n) {
        for (int i = 0; i < n; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
        exit(0);
    }

    for (int c = 1; c <= k; c++) {
        if (is_safe(v, c, n)) {
            color[v] = c;
            graph_coloring(v+1, n, k);
            color[v] = 0;
        }
    }
}

int main() {
    int n, k;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n > MAX_VERTICES) {
        printf("Too many vertices. Max allowed is %d", MAX_VERTICES);
        return -1;
    }

    printf("Enter number of colors: ");
    scanf("%d", &k);

    printf("Enter adjacency matrix of graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    graph_coloring(0, n, k);

    printf("No solution found.\n");
    return 0;
}