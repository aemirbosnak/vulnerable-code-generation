//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
// Single-threaded graph coloring problem example program
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
} Graph;

// Color structure
typedef struct {
    int* color;
    int* num_colors;
} Color;

// Initialize graph
void init_graph(Graph* graph, int num_vertices, int num_edges) {
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adjacency_matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = (int*)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
}

// Free graph memory
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
}

// Add edge to graph
void add_edge(Graph* graph, int v1, int v2) {
    graph->adjacency_matrix[v1][v2] = 1;
    graph->adjacency_matrix[v2][v1] = 1;
}

// Print graph
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Check if graph is bipartite
int is_bipartite(Graph* graph) {
    int* color = (int*)malloc(graph->num_vertices * sizeof(int));
    for (int i = 0; i < graph->num_vertices; i++) {
        color[i] = 0;
    }
    for (int i = 0; i < graph->num_vertices; i++) {
        if (color[i] == 0) {
            if (!dfs_visit(graph, i, color)) {
                return 0;
            }
        }
    }
    return 1;
}

// DFS visit function
int dfs_visit(Graph* graph, int v, int* color) {
    color[v] = 1;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[v][i] == 1 && color[i] == 0) {
            if (!dfs_visit(graph, i, color)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Initialize graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    init_graph(graph, 4, 4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 0);

    // Print graph
    printf("Graph:\n");
    print_graph(graph);

    // Check if graph is bipartite
    if (is_bipartite(graph)) {
        printf("Graph is bipartite\n");
    } else {
        printf("Graph is not bipartite\n");
    }

    // Free graph memory
    free_graph(graph);
    free(graph);

    return 0;
}