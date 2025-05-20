//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef enum _bool {
    false = 0,
    true = 1
} bool;

int vertices, edges, colors;
int graph[MAX_VERTICES][MAX_VERTICES];
int vertex_colors[MAX_VERTICES];

bool is_valid_coloring(int vertex, int color) {
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && color == vertex_colors[i]) {
            return false;
        }
    }
    return true;
}

bool color_graph(int vertex) {
    if (vertex == vertices) {
        return true;
    }
    for (int i = 1; i <= colors; i++) {
        if (is_valid_coloring(vertex, i)) {
            vertex_colors[vertex] = i;
            if (color_graph(vertex + 1)) {
                return true;
            }
        }
    }
    vertex_colors[vertex] = 0;
    return false;
}

int main() {
    // Get input from user
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the number of colors: ");
    scanf("%d", &colors);

    // Initialize graph
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Get edges from user and build graph
    printf("Enter the edges (vertex1 vertex2): \n");
    int vertex1, vertex2;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    // Color graph and print solution
    if (color_graph(0)) {
        printf("A valid coloring of the graph is:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d: color %d\n", i, vertex_colors[i]);
        }
    } else {
        printf("No valid coloring exists for this graph.\n");
    }

    return 0;
}