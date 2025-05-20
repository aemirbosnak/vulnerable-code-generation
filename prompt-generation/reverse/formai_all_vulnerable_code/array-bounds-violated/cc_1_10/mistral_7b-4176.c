//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50
#define MAX_EDGES 500

typedef struct {
    int start, end;
} Edge;

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int color[MAX_VERTICES];
int num_colors = 1;

bool is_valid_color(int vertex, int color_for_neighbor) {
    for (int i = 0; i < vertex; i++) {
        if (graph[i][vertex] != -1 && color[i] == color_for_neighbor) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int vertex) {
    if (vertex >= MAX_VERTICES) {
        return true;
    }

    visited[vertex] = true;
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] != -1) {
            int color_for_neighbor = color[i];
            if (!is_valid_color(vertex, color_for_neighbor)) {
                visited[vertex] = false;
                continue;
            }
            color[vertex] = color_for_neighbor + 1;
            if (graph_coloring(vertex + 1)) {
                return true;
            }
            color[vertex] = 0;
        }
    }

    if (vertex == 0) {
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (color[i] == 0) {
                return false;
            }
        }
        return true;
    }

    visited[vertex] = false;
    return false;
}

void read_graph_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");

    int vertices, edges;
    fscanf(file, "%d %d", &vertices, &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = -1;
        }
    }

    for (int i = 0; i < edges; i++) {
        int start, end;
        fscanf(file, "%d %d", &start, &end);
        graph[start][end] = i;
        graph[end][start] = i;
    }

    fclose(file);
}

int main() {
    read_graph_from_file("graph.txt");
    if (graph_coloring(0)) {
        printf("Graph can be colored with %d colors.\n", num_colors);
    } else {
        printf("Graph cannot be colored.\n");
    }

    return 0;
}