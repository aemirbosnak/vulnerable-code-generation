//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define INF 1000000000

// Define the graph structure
struct graph {
    int num_vertices;
    int num_edges;
    int** adjacency_matrix;
};

// Function to initialize the graph structure
struct graph* initialize_graph(int num_vertices, int num_edges) {
    struct graph* graph = malloc(sizeof(struct graph));
    assert(graph!= NULL);
    
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    
    graph->adjacency_matrix = malloc(num_vertices * sizeof(int*));
    assert(graph->adjacency_matrix!= NULL);
    
    for (int i = 0; i < num_vertices; i++) {
        graph->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
        assert(graph->adjacency_matrix[i]!= NULL);
    }
    
    return graph;
}

// Function to add an edge to the graph
void add_edge(struct graph* graph, int v1, int v2) {
    graph->adjacency_matrix[v1][v2] = 1;
    graph->adjacency_matrix[v2][v1] = 1;
}

// Function to find the minimum number of colors needed to color the graph
int min_colors(struct graph* graph) {
    int num_colors = 0;
    int num_nodes = graph->num_vertices;
    
    for (int i = 0; i < num_nodes; i++) {
        int colors[num_nodes];
        memset(colors, 0, num_nodes * sizeof(int));
        
        for (int j = 0; j < num_nodes; j++) {
            if (graph->adjacency_matrix[i][j] == 1) {
                colors[j] = 1;
            }
        }
        
        for (int k = 0; k < num_nodes; k++) {
            if (colors[k] == 0) {
                num_colors++;
            }
        }
    }
    
    return num_colors;
}

// Function to print the graph structure
void print_graph(struct graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int num_vertices, num_edges;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);
    
    struct graph* graph = initialize_graph(num_vertices, num_edges);
    
    printf("Enter edges in the form of (v1, v2):\n");
    for (int i = 0; i < num_edges; i++) {
        int v1, v2;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &v1, &v2);
        add_edge(graph, v1, v2);
    }
    
    printf("Minimum number of colors needed: %d\n", min_colors(graph));
    print_graph(graph);
    
    free(graph->adjacency_matrix);
    free(graph);
    
    return 0;
}