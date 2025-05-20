//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];   // to represent the graph
int colors[MAX_VERTICES];   // to keep track of the colors assigned to vertices
int V;   // number of vertices in the graph

bool isValid(int vertex, int color) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool coloring(int vertex, int n_colors) {
    if (vertex == V) {
        // all vertices are colored
        return true;
    }

    for (int c = 1; c <= n_colors; c++) {
        if (isValid(vertex, c)) {
            colors[vertex] = c;
            if (coloring(vertex + 1, n_colors)) {
                return true;
            }
            colors[vertex] = 0;   // backtrack
        }
    }
    return false;   // can't color vertex with given colors
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int n_colors;
    printf("Enter the number of colors: ");
    scanf("%d", &n_colors);

    if (coloring(0, n_colors)) {
        printf("Coloring possible with %d colors.\n", n_colors);
        printf("Colors of vertices:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Coloring not possible with %d colors.\n", n_colors);
    }
    return 0;
}