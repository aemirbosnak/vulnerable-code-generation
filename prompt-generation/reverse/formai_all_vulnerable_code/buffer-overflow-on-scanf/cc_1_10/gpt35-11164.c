//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

// The graph structure
typedef struct graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Color the vertices of the graph
void colorVertices(Graph *g, int colors[]) {
    int i, j, k, min_color;
    int available_colors[MAX_VERTICES];
    memset(available_colors, 0, sizeof(available_colors));

    // Color the first vertex with the first color
    colors[0] = 0;

    // Assign colors to remaining vertices
    for (i = 1; i < g->num_vertices; i++) {
        // Mark all the colors as available
        memset(available_colors, 0, sizeof(available_colors));

        // Find the adjacent vertices and mark their colors as unavailable
        for (j = 0; j < g->num_vertices; j++) {
            if (g->adj_matrix[i][j]) {
                if (colors[j] >= 0) {
                    available_colors[colors[j]] = 1;
                }
            }
        }

        // Find the smallest available color
        min_color = 0;
        for (k = 1; k < g->num_vertices; k++) {
            if (available_colors[k] == 0) {
                min_color = k;
                break;
            }
        }

        // Assign the min available color to the current vertex
        colors[i] = min_color;
    }
}

int main() {
    int i, j;
    Graph g = {0};
    int num_vertices;
    int colors[MAX_VERTICES];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    g.num_vertices = num_vertices;

    printf("Enter the adjacency matrix of the graph (0 or 1):\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            scanf("%d", &g.adj_matrix[i][j]);
        }
    }

    // Color the vertices of the graph
    colorVertices(&g, colors);

    // Print the colors of the vertices
    printf("The colors of the vertices are:");
    for (i = 0; i < num_vertices; i++) {
        printf(" %d", colors[i]);
    }

    return 0;
}