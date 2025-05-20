//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 50

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
int num_colors;

bool is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(int v) {
    if (v == num_vertices) {
        return true;
    }

    for (int c = 1; c <= num_colors; c++) {
        if (is_safe(v, c)) {
            colors[v] = c;

            if (graph_coloring(v + 1)) {
                return true;
            }

            colors[v] = 0;
        }
    }

    return false;
}


int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    if (graph_coloring(0)) {
        printf("The graph can be colored with %d colors as:\n", num_colors);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", num_colors);
    }

    return 0;
}