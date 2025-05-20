//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

/* Function to check if coloring is safe */
bool isSafe(int vertex, int c, int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && c == color[i])
            return false;
    }
    return true;
}

/* Function to assign colors recursively */
bool assignColors(int vertex, int vertices, int numColors) {
    if (vertex == vertices)
        return true;

    for (int c = 1; c <= numColors; c++) {
        if (isSafe(vertex, c, vertices)) {
            color[vertex] = c;
            if (assignColors(vertex + 1, vertices, numColors))
                return true;
            color[vertex] = 0;
        }
    }

    return false;
}

/* Driver function to solve Graph Coloring Problem */
int main() {
    int vertices, edges, numColors;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the maximum number of colors: ");
    scanf("%d", &numColors);

    /* Initialize graph */
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        color[i] = 0;
    }

    /* Populate graph */
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge %d (u -> v): ", i+1);
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }

    /* Assign and print colors */
    if (assignColors(0, vertices, numColors)) {
        printf("Colors Assigned Successfully:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, color[i]);
        }
    } else {
        printf("Coloring not possible with %d colors\n", numColors);
    }

    return 0;
}