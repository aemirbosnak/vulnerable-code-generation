//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int num_vertices, num_edges;

bool is_safe(int vertex, int color_assigned) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color[i] == color_assigned)
            return false;
    }
    return true;
}

int graph_coloring(int vertex) {
    if (color[vertex] != -1)
        return color[vertex];

    int min_color = MAX_COLOR;
    for (int i = MIN_COLOR; i <= MAX_COLOR; i++) {
        if (is_safe(vertex, i)) {
            color[vertex] = i;
            for (int neighbor = 0; neighbor < num_vertices; neighbor++) {
                if (graph[vertex][neighbor] && color[neighbor] == -1) {
                    int result = graph_coloring(neighbor);
                    if (result == -1) {
                        color[vertex] = -1;
                        break;
                    }
                }
            }
            if (color[vertex] != -1)
                return color[vertex];
        }
        if (i > min_color)
            min_color = i;
    }
    return -1;
}

int main() {
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &num_vertices, &num_edges);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) {
                graph[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        color[i] = -1;
    }

    int first_vertex = 0;
    int num_colors = graph_coloring(first_vertex);

    printf("Minimum number of colors required: %d\n", num_colors);

    return 0;
}