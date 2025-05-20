//GPT-4o-mini DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Function to create a graph
Graph* create_graph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj_matrix[i][j] = 0; // Initialize adjacency matrix
        }
    }
    return g;
}

// Function to add edge to the graph
void add_edge(Graph* g, int start, int end) {
    if (start >= g->num_vertices || end >= g->num_vertices || start < 0 || end < 0) {
        printf("Error: Vertex out of bounds.\n");
        return;
    }
    g->adj_matrix[start][end] = 1; // Directed edge from start to end
    g->adj_matrix[end][start] = 1; // For undirected graph
}

// Function to print the adjacency matrix
void print_graph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Depth-First Search (DFS)
void dfs(Graph* g, int vertex, int* visited) {
    visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex);

    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_matrix[vertex][i] == 1 && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

// Function to perform Depth-First Search
void depth_first_search(Graph* g, int start_vertex) {
    int* visited = (int*)calloc(g->num_vertices, sizeof(int));
    printf("Depth-First Search starting from vertex %d:\n", start_vertex);
    dfs(g, start_vertex, visited);
    free(visited);
}

// Function to free the memory allocated for the graph
void free_graph(Graph* g) {
    free(g);
}

int main() {
    int vertices;
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES || vertices <= 0) {
        printf("Invalid number of vertices. Exiting.\n");
        return 1;
    }

    Graph* g = create_graph(vertices);

    // Adding some edges
    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);
    
    // Display the graph
    print_graph(g);

    // Perform depth first search
    depth_first_search(g, 0);

    // Free the graph
    free_graph(g);

    return 0;
}