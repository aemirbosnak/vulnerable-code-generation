//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;
int colors[MAX_VERTICES];
int num_colors = 0;

void clear_colors() {
    for(int i = 0; i < vertices; i++) {
        colors[i] = -1;
    }
}

/* A utility function to check if the current color assignment is safe for vertex v */
int is_safe(int v, int color) {
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && color == colors[i]) {
            return 0;
        }
    }
    return 1;
}

int color_vertices(int v) {
    if (v == vertices) {
        return 1;
    }
    for (int c = 0; c < num_colors; c++) {
        if (is_safe(v, c)) {
            colors[v] = c;
            if (color_vertices(v + 1)) {
                return 1;
            }
            colors[v] = -1;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize all edges to 0
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Get edges
    printf("Enter the number of edges: ");
    int num_edges;
    scanf("%d", &num_edges);

    for(int i = 0; i < num_edges; i++) {
        printf("Enter the vertices for edge %d: ", i+1);
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // Find the minimum number of colors needed
    clear_colors();
    color_vertices(0);
    for (int i = 0; i < vertices; i++) {
        if (colors[i] == -1) {
            num_colors++;
            clear_colors();
            color_vertices(0);
        }
    }

    printf("Minimum number of colors needed: %d\n", num_colors);
    return 0;
}