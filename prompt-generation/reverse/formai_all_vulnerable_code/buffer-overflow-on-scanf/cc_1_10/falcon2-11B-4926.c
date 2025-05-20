//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to perform graph coloring
void graph_coloring(int V, int E, int vertices[V][V], int edges[E][2], int color[V], int parent[V]) {
    // Initialize color array with maximum color value
    int color_max = INT_MAX;
    for (int i = 0; i < V; i++) {
        color[i] = color_max;
    }

    // Set parent array to -1
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    // Perform graph coloring algorithm
    for (int i = 0; i < V; i++) {
        if (color[i] == color_max) {
            // Find an uncolored vertex
            for (int j = 0; j < E; j++) {
                if (edges[j][0] == i && edges[j][1]!= i) {
                    // Assign color to the uncolored vertex and its adjacent vertices
                    int neighbor = edges[j][1];
                    color[i] = 1;
                    color[neighbor] = 1;

                    // Update parent array
                    parent[i] = neighbor;
                    parent[neighbor] = i;

                    // Recolor other adjacent vertices of the uncolored vertex
                    for (int k = 0; k < E; k++) {
                        if (edges[k][0] == i && edges[k][1]!= i) {
                            int neighbor = edges[k][1];
                            if (color[neighbor] == color_max) {
                                color[neighbor] = 1;
                                parent[neighbor] = i;
                            }
                        }
                    }

                    // Recolor uncolored vertex
                    color[i]++;
                    color_max = INT_MAX;
                    for (int k = 0; k < V; k++) {
                        if (color[k] > color[i]) {
                            color_max = color[k];
                        }
                    }
                }
            }
        }
    }

    // Print the coloring result
    printf("Graph Coloring Result:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");

    // Print the parent array
    printf("Parent Array:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", parent[i]);
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    int vertices[V][V];
    int edges[E][2];
    int color[V];
    int parent[V];

    // Input the graph vertices
    for (int i = 0; i < V; i++) {
        printf("Enter vertices of vertex %d:\n", i);
        for (int j = 0; j < V; j++) {
            scanf("%d", &vertices[i][j]);
        }
    }

    // Input the graph edges
    for (int i = 0; i < E; i++) {
        printf("Enter edges (%d) of vertex %d:\n", i+1, edges[i][0]);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Perform graph coloring
    graph_coloring(V, E, vertices, edges, color, parent);

    return 0;
}