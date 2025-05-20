//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices, num_colors;
int color[MAX_VERTICES];

void print_colors() {
    printf("Coloring Solution:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

int graph_color(int v) {
    if (v == num_vertices) {
        return 1;
    }

    for (int c = 1; c <= num_colors; c++) {
        if (is_safe(v, c)) {
            color[v] = c;
            if (graph_color(v+1)) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &num_colors);

    if (graph_color(0)) {
        print_colors();
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}