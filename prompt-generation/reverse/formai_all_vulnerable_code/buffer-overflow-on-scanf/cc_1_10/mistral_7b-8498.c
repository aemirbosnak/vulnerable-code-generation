//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define COLOR_MAX 10

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int color[MAX_VERTICES];
} Graph;

void dfs(Graph *graph, int vertex, int color) {
    graph->color[vertex] = color;

    for (int neighbor = 0; neighbor < MAX_VERTICES; neighbor++) {
        if (graph->adj_matrix[vertex][neighbor] && graph->color[neighbor] == -1) {
            dfs(graph, neighbor, (color + 1) % COLOR_MAX);
        } else if (graph->color[neighbor] == color) {
            printf("Graph has a cycle with color %d.\n", color);
            exit(1);
        }
    }
}

int main() {
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    Graph graph;
    memset(&graph, 0, sizeof(Graph));

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph.adj_matrix[u][v] = graph.adj_matrix[v][u] = 1;
    }

    int min_color = COLOR_MAX;

    for (int vertex = 0; vertex < vertices; vertex++) {
        if (graph.color[vertex] == -1) {
            dfs(&graph, vertex, MIN_COLOR);
            min_color = (min_color > graph.color[vertex] + 1) ? graph.color[vertex] + 1 : min_color;
        }
    }

    printf("Minimum number of colors required to color the graph: %d\n", min_color);

    return 0;
}