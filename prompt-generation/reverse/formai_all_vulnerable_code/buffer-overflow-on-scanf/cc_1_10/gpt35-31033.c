//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices, num_colors;
int color[MAX_VERTICES];

void init_colors() {
    for (int i = 0; i < num_vertices; i++) {
        color[i] = 0;
    }
}

void assign_color(int vertex) {
    int available[num_colors];
    for (int i = 0; i < num_colors; i++) {
        available[i] = 1;
    }
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color[i] != 0) {
            available[color[i] - 1] = 0;
        }
    }
    for (int i = 0; i < num_colors; i++) {
        if (available[i]) {
            color[vertex] = i + 1;
            break;
        }
    }
}

void graph_coloring() {
    init_colors();
    for (int i = 0; i < num_vertices; i++) {
        assign_color(i);
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    graph_coloring();
    printf("The assigned colors are:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i + 1, color[i]);
    }
    return 0;
}