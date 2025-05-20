//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A graph is represented as an adjacency list. Each node in the graph is represented by an integer,
// and each edge in the graph is represented by a pair of integers.
typedef struct {
    int num_nodes;
    int num_edges;
    int **adj_list;
} graph;

// A coloring of a graph is represented as an array of integers, where each element of the array
// represents the color of the corresponding node in the graph.
typedef int* coloring;

// Given a graph and a coloring, this function checks if the coloring is valid. A coloring is valid
// if no two adjacent nodes have the same color.
bool is_valid_coloring(graph *g, coloring c) {
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->adj_list[i][0]; j++) {
            int neighbor = g->adj_list[i][j + 1];
            if (c[i] == c[neighbor]) {
                return false;
            }
        }
    }
    return true;
}

// Given a graph, this function finds a valid coloring for the graph. If no valid coloring exists,
// the function returns NULL.
coloring find_coloring(graph *g) {
    // The coloring will be stored in this array.
    coloring c = malloc(sizeof(int) * g->num_nodes);
    
    // Initialize the coloring to all 0s. This represents an uncolored graph.
    for (int i = 0; i < g->num_nodes; i++) {
        c[i] = 0;
    }
    
    // The coloring is found using a greedy algorithm. We start by coloring the first node with
    // the first color. Then, we color each subsequent node with the first color that is not
    // already used by any of its neighbors.
    int current_color = 1;
    for (int i = 0; i < g->num_nodes; i++) {
        // If the node is already colored, skip it.
        if (c[i] != 0) {
            continue;
        }
        
        // Try to color the node with the current color.
        c[i] = current_color;
        
        // If the coloring is not valid, try the next color.
        while (!is_valid_coloring(g, c)) {
            current_color++;
            c[i] = current_color;
        }
    }
    
    // Return the coloring.
    return c;
}

// Given a graph, this function prints the graph's adjacency list.
void print_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->adj_list[i][0]; j++) {
            printf("%d ", g->adj_list[i][j + 1]);
        }
        printf("\n");
    }
}

// Given a graph and a coloring, this function prints the coloring.
void print_coloring(graph *g, coloring c) {
    for (int i = 0; i < g->num_nodes; i++) {
        printf("%d: %d\n", i, c[i]);
    }
}

// This function creates a graph from a file. The file should contain the number of nodes and edges in
// the graph, followed by the edges themselves. Each edge should be represented by a pair of integers,
// representing the two nodes that the edge connects.
graph* create_graph_from_file(char *filename) {
    // Open the file.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    // Read the number of nodes and edges from the file.
    int num_nodes, num_edges;
    fscanf(fp, "%d %d", &num_nodes, &num_edges);
    
    // Create the graph.
    graph *g = malloc(sizeof(graph));
    g->num_nodes = num_nodes;
    g->num_edges = num_edges;
    g->adj_list = malloc(sizeof(int *) * num_nodes);
    
    // Read the edges from the file.
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        
        // Add the edge to the graph.
        g->adj_list[u] = realloc(g->adj_list[u], sizeof(int) * (g->adj_list[u][0] + 2));
        g->adj_list[u][0]++;
        g->adj_list[u][g->adj_list[u][0]] = v;
        
        // Add the edge to the transpose of the graph.
        g->adj_list[v] = realloc(g->adj_list[v], sizeof(int) * (g->adj_list[v][0] + 2));
        g->adj_list[v][0]++;
        g->adj_list[v][g->adj_list[v][0]] = u;
    }
    
    // Close the file.
    fclose(fp);
    
    // Return the graph.
    return g;
}

// This function frees the memory allocated for a graph.
void free_graph(graph *g) {
    for (int i = 0; i < g->num_nodes; i++) {
        free(g->adj_list[i]);
    }
    free(g->adj_list);
    free(g);
}

// This function frees the memory allocated for a coloring.
void free_coloring(coloring c) {
    free(c);
}

// This is the main function.
int main(int argc, char **argv) {
    // Create the graph.
    graph *g = create_graph_from_file("graph.txt");
    
    // Print the graph.
    printf("Graph:\n");
    print_graph(g);
    
    // Find a coloring for the graph.
    coloring c = find_coloring(g);
    
    // Print the coloring.
    printf("Coloring:\n");
    print_coloring(g, c);
    
    // Free the memory allocated for the graph and the coloring.
    free_graph(g);
    free_coloring(c);
    
    return 0;
}