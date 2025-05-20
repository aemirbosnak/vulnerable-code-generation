//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum number of vertices

int graph[MAX][MAX]; // adjacency matrix representation of graph
int color[MAX]; // stores the color of each vertex
int num_vertices, num_colors;

// function to check if it is safe to color a vertex with a given color
int is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0; // vertex i is adjacent to vertex v and has the same color
        }
    }
    return 1;
}

// function to recursively color the vertices
int graph_coloring(int v) {
    // base case: all vertices have been colored
    if (v == num_vertices) {
        return 1;
    }

    // try all possible colors for vertex v
    for (int c = 1; c <= num_colors; c++) {
        if (is_safe(v, c)) {
            color[v] = c; // set the color of vertex v to c

            // recursively color the remaining vertices starting from vertex v+1
            if (graph_coloring(v+1)) {
                return 1;
            }

            color[v] = 0; // reset the color of vertex v
        }
    }

    return 0; // no valid coloring found
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    if (graph_coloring(0)) {
        printf("Valid coloring found:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, color[i]);
        }
    } else {
        printf("No valid coloring found.\n");
    }

    return 0;
}