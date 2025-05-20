//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void colorGraph(int vertices, int graph[MAX_VERTICES][MAX_VERTICES], int colors[]) {
    int i, j, k;
    int available_colors[MAX_VERTICES];

    // Initialize all vertices as uncolored
    for (i = 0; i < vertices; i++) {
        colors[i] = -1;
    }

    // Assign color to the first vertex
    colors[0] = 0;

    // Available colors for the rest of the vertices initially is all colors
    for (i = 0; i < vertices; i++) {
        available_colors[i] = 1;
    }

    // Assign colors to the remaining vertices
    for (i = 1; i < vertices; i++) {
        // Reset available colors for the current vertex
        for (j = 0; j < vertices; j++) {
            available_colors[j] = 1;
        }

        // Check the colors assigned to adjacent vertices and 
        // mark them as unavailable
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] && colors[j] != -1) {
                available_colors[colors[j]] = 0;
            }
        }

        // Assign the first available color
        for (k = 0; k < vertices; k++) {
            if (available_colors[k]) {
                colors[i] = k;
                break;
            }
        }
    }
}

int main() {
    int vertices, edges, i, j, vertex1, vertex2;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &vertices, &edges);

    int graph[MAX_VERTICES][MAX_VERTICES];
    int colors[MAX_VERTICES];

    // Initialize the graph
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    printf("Enter the vertices of each edge: \n");
    for (i = 0; i < edges; i++) {
        scanf("%d%d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    // Color the graph
    colorGraph(vertices, graph, colors);

    // Print the colors assigned to the vertices
    printf("Colors assigned to the vertices are: \n");
    for (i = 0; i < vertices; i++) {
        printf("Vertex %d -> Color %d \n", i, colors[i]);
    }

    return 0;
}