//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int degree[MAX_VERTICES];

int color[MAX_VERTICES];
int num_vertices;
int num_colors;

bool is_valid(int vertex, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[vertex][i] && c == color[i])
            return false;
    }
    return true;
}

bool graph_color(int vertex) {
    if (vertex == num_vertices)
        return true;
    for (int c = 1; c <= num_colors; c++) {
        if (is_valid(vertex, c)) {
            color[vertex] = c;
            if (graph_color(vertex + 1))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        degree[i] = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j])
                degree[i]++;
        }
    }

    if (graph_color(0)) {
        printf("The coloring of the graph is: \n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d \n", i + 1, color[i]);
        }
    }
    else {
        printf("No solution exists!\n");
    }

    return 0;
}