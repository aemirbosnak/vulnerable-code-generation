//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_COLOR 10
#define MAX_VERTEX 1000

// Function to print the vertices of the graph
void print_vertices(int vertices[], int num_vertices) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, vertices[i]);
    }
}

// Function to print the edges of the graph
void print_edges(int edges[], int num_edges) {
    int i;
    for (i = 0; i < num_edges; i++) {
        printf("Edge %d: %d -> %d\n", i, edges[2*i], edges[2*i+1]);
    }
}

// Function to check if a vertex is colored or not
int is_colored(int color[], int vertices[], int num_vertices, int vertex) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (color[i] == vertex) {
            return 1;
        }
    }
    return 0;
}

// Function to color a vertex
int color_vertex(int color[], int vertices[], int num_vertices, int vertex) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (color[i] == vertex) {
            return 1;
        }
    }
    color[num_vertices] = vertex;
    return 0;
}

// Function to perform graph coloring
int graph_color(int edges[], int num_edges, int vertices[], int num_vertices) {
    int i, j, color[num_vertices], edge_color[MAX_COLOR];
    int num_colors = 0;

    for (i = 0; i < num_vertices; i++) {
        color[i] = 0;
    }

    // Initialize the edge color array
    for (i = 0; i < num_edges; i++) {
        edge_color[i] = -1;
    }

    // Perform graph coloring
    for (i = 0; i < num_edges; i++) {
        j = edges[2*i];
        edge_color[i] = color_vertex(color, vertices, num_vertices, j);
        if (edge_color[i] == 0) {
            color_vertex(color, vertices, num_vertices, i);
            num_colors++;
        }
    }

    // Check if graph is properly colored
    for (i = 0; i < num_edges; i++) {
        if (edge_color[i] == -1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int vertices[MAX_VERTEX], edges[MAX_VERTEX*2], num_vertices, num_edges, i, j;
    int color[MAX_VERTEX];

    // Input graph vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter %d vertices:\n", num_vertices);
    for (i = 0; i < num_vertices; i++) {
        scanf("%d", &vertices[i]);
    }
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter %d edges:\n", num_edges);
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &edges[2*i], &edges[2*i+1]);
    }

    // Call graph coloring function
    graph_color(edges, num_edges, vertices, num_vertices);

    // Print the result
    if (graph_color(edges, num_edges, vertices, num_vertices)) {
        printf("Graph is properly colored!\n");
    } else {
        printf("Graph is not properly colored!\n");
    }

    // Print vertices and edges
    print_vertices(vertices, num_vertices);
    print_edges(edges, num_edges);

    return 0;
}