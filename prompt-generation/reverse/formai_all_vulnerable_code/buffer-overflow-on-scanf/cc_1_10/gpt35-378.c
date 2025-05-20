//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int vertices, edges;

bool isSafe(int v, int color) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graphColor(int v) {
    if (v == vertices) {
        return true;
    }

    for (int i = 1; i <= vertices; i++) {
        if (isSafe(v, i)) {
            colors[v] = i;
            if (graphColor(v + 1)) {
                return true;
            }
            colors[v] = 0;
        }
    }

    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int u, v;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if (graphColor(0)) {
        printf("Graph coloring is possible with the following colors:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph coloring is not possible.");
    }

    return 0;
}