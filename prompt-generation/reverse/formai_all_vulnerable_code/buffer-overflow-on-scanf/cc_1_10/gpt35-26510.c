//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;

bool is_color_safe(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int vertex) {
    if (vertex == num_vertices) {
        return true;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (is_color_safe(vertex, i)) {
            colors[vertex] = i;
            if (graph_coloring(vertex + 1)) {
                return true;
            }
            colors[vertex] = -1;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of vertices : ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }

    if (graph_coloring(0)) {
        printf("Solution exists:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}