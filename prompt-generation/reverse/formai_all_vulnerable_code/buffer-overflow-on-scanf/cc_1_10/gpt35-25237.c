//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define TRUE 1
#define FALSE 0

int graph[MAX_VERTICES][MAX_VERTICES];
int degree[MAX_VERTICES];
int color[MAX_VERTICES];
int num_vertices;

int isPromising(int vertex, int c) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && c == color[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

void printGraph() {
    int i, j;
    printf("Graph:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printColors() {
    int i;
    printf("Colors:\n");
    for (i = 0; i < num_vertices; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

void colorVertices(int vertex) {
    int i, c;
    if (vertex == num_vertices) {
        printColors();
        return;
    }
    for (c = 1; c <= 4; c++) {
        if (isPromising(vertex, c)) {
            color[vertex] = c;
            colorVertices(vertex + 1);
            color[vertex] = 0;
        }
    }
}

int main() {
    int i, j, x, y;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    // Initialize the graph matrix and degree array
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
        degree[i] = 0;
    }

    // Populate the graph matrix
    printf("Enter the edges (as vertex pairs):\n");
    while (scanf("%d %d", &x, &y) == 2) {
        if (x >= num_vertices || y >= num_vertices) {
            printf("Error: vertex out of range\n");
            continue;
        }
        graph[x][y] = 1;
        graph[y][x] = 1;
        degree[x]++;
        degree[y]++;
    }

    // Print the graph
    printGraph();

    // Color the vertices
    colorVertices(0);

    return 0;
}