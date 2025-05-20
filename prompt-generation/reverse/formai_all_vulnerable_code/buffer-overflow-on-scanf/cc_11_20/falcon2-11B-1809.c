//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct node {
    int vertex;
    int color;
} node;

int min_color[MAX_VERTICES];
int num_colors;

node graph[MAX_VERTICES][MAX_VERTICES];

int main() {
    int num_vertices, num_edges, i, j, k, color;

    // Read the number of vertices and edges
    scanf("%d%d", &num_vertices, &num_edges);

    // Initialize the graph with all vertices
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j].vertex = 0;
            graph[i][j].color = 0;
        }
    }

    // Read the edges
    for (i = 0; i < num_edges; i++) {
        scanf("%d%d", &graph[i % num_vertices][(i + 1) % num_vertices].vertex, &graph[i % num_vertices][(i + 1) % num_vertices].color);
    }

    // Initialize the minimum color array
    for (i = 0; i < num_vertices; i++) {
        min_color[i] = 0;
    }

    // Find a minimum coloring of the graph
    for (color = 1; color <= num_vertices; color++) {
        for (i = 0; i < num_vertices; i++) {
            min_color[i] = 0;
        }

        // Assign colors to the vertices
        for (i = 0; i < num_vertices; i++) {
            min_color[i] = color;
        }

        // Recolor vertices with unassigned color
        for (i = 0; i < num_vertices; i++) {
            for (j = 0; j < num_vertices; j++) {
                if (graph[i][j].vertex == i && min_color[j] == 0) {
                    min_color[j] = color;
                }
            }
        }

        // Check if all vertices have been colored
        for (i = 0; i < num_vertices; i++) {
            if (min_color[i] == 0) {
                break;
            }
        }

        // If all vertices have been colored, break the loop
        if (i == num_vertices) {
            break;
        }
    }

    // Print the minimum coloring
    printf("Minimum Coloring: ");
    for (i = 0; i < num_vertices; i++) {
        printf("%d ", min_color[i]);
    }
    printf("\n");

    return 0;
}