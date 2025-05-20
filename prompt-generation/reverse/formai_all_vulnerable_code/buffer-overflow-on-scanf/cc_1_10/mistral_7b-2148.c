//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLOR 6

typedef struct {
    int vertex;
    int color;
} Node;

Node graph[MAX_VERTICES];
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int n_vertices, n_edges;
int available_colors[MAX_COLOR];
bool graph_is_colored[MAX_VERTICES];

void print_graph() {
    int i, j;
    for (i = 0; i < n_vertices; i++) {
        printf("Vertex %d: color %d\n", i, graph[i].color);
        for (j = 0; j < n_vertices; j++) {
            if (adjacency_matrix[i][j] != INT_MAX)
                printf("-- %d (color %d)\n", j, graph[j].color);
        }
    }
}

bool is_valid_color(int vertex, int color) {
    int i;
    for (i = 0; i < n_vertices; i++) {
        if (adjacency_matrix[vertex][i] != INT_MAX && graph[i].color == color)
            return false;
    }
    return true;
}

bool graph_coloring(int vertex) {
    int i, color;
    if (graph_is_colored[vertex])
        return true;

    for (color = 0; color < MAX_COLOR; color++) {
        if (is_valid_color(vertex, color)) {
            graph[vertex].color = color;
            graph_is_colored[vertex] = true;

            for (i = 0; i < n_vertices; i++) {
                if (adjacency_matrix[vertex][i] != INT_MAX) {
                    if (!graph_coloring(i)) {
                        graph[vertex].color = -1;
                        graph_is_colored[vertex] = false;
                        break;
                    }
                }
            }

            if (vertex == n_vertices - 1) {
                printf("\nGraph Coloring Solved!\n");
                print_graph();
                return true;
            }
        }
    }

    graph[vertex].color = -1;
    graph_is_colored[vertex] = false;
    return false;
}

void read_graph() {
    int i, j;
    scanf("%d %d", &n_vertices, &n_edges);

    for (i = 0; i < n_vertices; i++) {
        graph[i].vertex = i;
        graph[i].color = -1;
        graph_is_colored[i] = false;
    }

    for (i = 0; i < n_vertices; i++)
        for (j = 0; j < n_vertices; j++)
            adjacency_matrix[i][j] = INT_MAX;

    for (i = 0; i < n_edges; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adjacency_matrix[x][y] = adjacency_matrix[y][x] = 0;
    }

    for (i = 0; i < MAX_COLOR; i++)
        available_colors[i] = i;
}

int main() {
    clock_t start = clock();
    read_graph();
    graph_coloring(0);
    clock_t end = clock();
    printf("\nTime taken by the algorithm: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}