//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_EDGES 15
#define MAX_COLORS 4

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int vertices, edges;

int is_coloring_possible(int vertex, int color) {
    int i;
    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int vertex) {
    int i, color;
    if (vertex == vertices) {
        return 1;
    }
    for (color = 1; color <= MAX_COLORS; color++) {
        if (is_coloring_possible(vertex, color)) {
            colors[vertex] = color;
            if (graph_coloring(vertex + 1)) {
                return 1;
            }
            colors[vertex] = 0;
        }
    }
    return 0;
}

int main() {
    int i, j, x, y;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        colors[i] = 0;
    }
    printf("Enter the edges: ");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    if (graph_coloring(0)) {
        printf("\nThe colors assigned to the vertices are:\n");
        for (i = 0; i < vertices; i++) {
            printf("Vertex %d : Color %d\n", i, colors[i]);
        }
    } else {
        printf("\nColoring is not possible.\n");
    }
    return 0;
}