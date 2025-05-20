//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 1000

int num_vertices, num_edges;
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

bool is_safe(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int vertex) {
    if (vertex == num_vertices) {
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
        return true;
    }
    for (int i = 1; i <= num_vertices; i++) {
        if (is_safe(vertex, i)) {
            colors[vertex] = i;
            if (graph_coloring(vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter edges: \n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    if (!graph_coloring(0)) {
        printf("No solution exists.\n");
    }

    return 0;
}