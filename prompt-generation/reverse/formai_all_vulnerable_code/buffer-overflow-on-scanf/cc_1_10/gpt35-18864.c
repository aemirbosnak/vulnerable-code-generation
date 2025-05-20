//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100    // Maximum number of vertices
#define MAX_EDGES 500       // Maximum number of edges

int num_vertices;           // Number of vertices
int num_edges;              // Number of edges
int adj[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix

int color[MAX_VERTICES];    // Array for storing the color of each vertex

// Function prototypes
void read_graph();
int is_safe(int v, int c);
int graph_color(int v);

// Main function
int main() {
    read_graph();   // Read the graph from standard input
    int result = graph_color(0);    // Call the graph_color function on the first vertex
    
    if (result == 0) {
        printf("Solution does not exist.");
    } else {
        printf("The graph can be colored with %d colors.\n", result);
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, color[i]);
        }
    }
    
    return 0;
}

// Function for reading the graph from standard input
void read_graph() {
    scanf("%d %d", &num_vertices, &num_edges);
    
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u-1][v-1] = 1;
        adj[v-1][u-1] = 1;
    }
}

// Function for checking if it safe to color the vertex with the given color
int is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (adj[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Recursive function for coloring the vertices
int graph_color(int v) {
    if (v == num_vertices) {
        return 1;   // All vertices have been colored
    }
    
    for (int i = 1; i <= num_vertices; i++) {
        if (is_safe(v, i)) {
            color[v] = i;
            if (graph_color(v+1)) {
                return i;
            }
            color[v] = 0;
        }
    }
    
    return 0;   // No solution exists
}