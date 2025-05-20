//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int adj[MAX][MAX], n, color[MAX];

void graph_input() {
    int i, max_edges, origin, destin;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    max_edges = n * (n - 1);
    for (i = 0; i < max_edges; i++) {
        printf("Enter edge %d (-1 -1 to quit)\n", i + 1);
        printf("Enter origin: ");
        scanf("%d", &origin);
        printf("Enter destination: ");
        scanf("%d", &destin);

        if ((origin == -1) && (destin == -1))
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--;
        } else {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
        }
    }
}

void graph_output() {
    int i, j;

    printf("Adjacency matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int v, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (adj[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

int graph_color(int v) {
    int c;
    if (v == n)
        return 1;
    for (c = 1; c <= n; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graph_color(v + 1))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    graph_input();
    graph_output();

    if (graph_color(0)) {
        printf("Coloring possible: \n");
        int i;
        for (i = 0; i < n; i++)
            printf("Vertex %d: Color %d\n", i, color[i]);
    } else {
        printf("Coloring not possible.\n");
    }
    return 0;
}