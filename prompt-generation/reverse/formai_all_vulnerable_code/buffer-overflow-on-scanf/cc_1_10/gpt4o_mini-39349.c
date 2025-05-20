//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50  // Maximum number of vertices
#define INF 999999       // Infinity representation for unconnected edges

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;

// Function to check if it is safe to color vertex 'v' with color 'c'
int is_safe(int v, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] == 1 && colors[i] == c) {
            return 0;  // Not safe if adjacent vertex has the same color
        }
    }
    return 1;  // Safe to color vertex 'v' with color 'c'
}

// Function that tries to solve the graph coloring problem
int graph_coloring_util(int m, int v) {
    // If all vertices are assigned a color, return true
    if (v == num_vertices) {
        return 1;
    }

    // Try assigning colors 1 to m to the vertex v
    for (int c = 1; c <= m; c++) {
        if (is_safe(v, c)) {
            colors[v] = c;  // Assign color c to vertex v

            // Recur to assign colors to the next vertex
            if (graph_coloring_util(m, v + 1)) {
                return 1;
            }

            // If assigning color c doesn't lead to a solution, remove it
            colors[v] = 0;
        }
    }
    return 0;  // Backtrack
}

// Function to initiate the graph coloring
int graph_coloring(int m) {
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = 0;  // Initialize all vertices as uncolored
    }
    
    if (graph_coloring_util(m, 0)) {
        return 1;  // Found a solution
    }
    return 0;  // No solution exists
}

// Function to read the graph from the user
void read_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// Function to display the coloring result
void print_result() {
    printf("Color assignment for the graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    }
}

int main() {
    printf("Graph Coloring Problem\n");
    read_graph();

    int m; // Number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (graph_coloring(m)) {
        print_result();  // Print the result if successful
    } else {
        printf("No solution exists with %d colors.\n", m);
    }

    return 0;
}