//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void dfs(Graph *graph, int vertex, int color) {
    graph->adj_matrix[vertex][vertex] = color;

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] != -1 && graph->adj_matrix[vertex][i] != color) {
            if (graph->adj_matrix[i][vertex] == -1) {
                graph->adj_matrix[i][vertex] = color ^ 1;
                dfs(graph, i, color ^ 1);
            } else {
                printf("Graph Coloring Problem: No valid coloring exists.\n");
                exit(1);
            }
        }
    }
}

int main() {
    int vertices, edges;
    Graph graph;

    scanf("%d %d", &vertices, &edges);

    graph.num_vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph.adj_matrix[i][j] = -1;
        }
    }

    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        graph.adj_matrix[v1][v2] = 0;
        graph.adj_matrix[v2][v1] = 0;
    }

    int color = MIN_COLOR;
    for (int i = 0; i < graph.num_vertices; i++) {
        if (graph.adj_matrix[i][i] == -1) {
            dfs(&graph, i, color++);
        }
    }

    printf("Graph Coloring:\n");
    for (int i = 0; i < graph.num_vertices; i++) {
        printf("%d: %d\n", i, graph.adj_matrix[i][i]);
    }

    return 0;
}