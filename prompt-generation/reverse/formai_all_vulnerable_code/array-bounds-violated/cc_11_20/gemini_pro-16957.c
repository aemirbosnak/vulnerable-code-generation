//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int main() {
    int n, m;  // Number of vertices and edges
    int graph[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix
    int colors[MAX_VERTICES];  // Color assigned to each vertex

    // Read input
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // Initialize colors
    for (int i = 0; i < n; i++) {
        colors[i] = -1;
    }

    // Color the graph
    int chromatic_number = 0;
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            chromatic_number++;
            colors[i] = 0;
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1 && colors[j] == colors[i]) {
                    printf("Graph is not colorable.\n");
                    return 0;
                }
            }
            for (int j = 1; j < MAX_COLORS; j++) {
                int valid = 1;
                for (int k = 0; k < n; k++) {
                    if (graph[i][k] == 1 && colors[k] == j) {
                        valid = 0;
                        break;
                    }
                }
                if (valid) {
                    colors[i] = j;
                    break;
                }
            }
        }
    }

    // Print the result
    printf("Chromatic number: %d\n", chromatic_number);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }

    return 0;
}