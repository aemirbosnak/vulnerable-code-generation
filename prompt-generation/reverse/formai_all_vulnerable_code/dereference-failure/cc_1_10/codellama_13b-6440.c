//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
/*
 * Graph representation example program in Dennis Ritchie style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Graph structure
struct graph {
    int num_vertices;
    int num_edges;
    int* edges[MAX_VERTICES];
    int* weights[MAX_EDGES];
};

// Function to add an edge to the graph
void add_edge(struct graph* g, int src, int dest, int weight) {
    g->edges[src] = (int*)malloc(sizeof(int));
    g->edges[src][0] = dest;
    g->weights[src] = (int*)malloc(sizeof(int));
    g->weights[src][0] = weight;
    g->num_edges++;
}

// Function to remove an edge from the graph
void remove_edge(struct graph* g, int src, int dest) {
    int* temp = g->edges[src];
    g->edges[src] = (int*)malloc(sizeof(int) * (g->num_edges - 1));
    int i = 0;
    while (temp[i] != dest) {
        g->edges[src][i] = temp[i];
        i++;
    }
    free(temp);
    g->num_edges--;
}

// Function to print the graph
void print_graph(struct graph* g) {
    printf("Graph: \n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g->num_edges; j++) {
            if (g->edges[i][j] != -1) {
                printf("(%d, %d) ", g->edges[i][j], g->weights[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to initialize the graph
void init_graph(struct graph* g, int num_vertices) {
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        g->edges[i] = (int*)malloc(sizeof(int) * (g->num_edges + 1));
        g->weights[i] = (int*)malloc(sizeof(int) * (g->num_edges + 1));
        g->edges[i][0] = -1;
        g->weights[i][0] = -1;
    }
}

// Function to free the graph
void free_graph(struct graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->edges[i]);
        free(g->weights[i]);
    }
    free(g->edges);
    free(g->weights);
    free(g);
}

int main() {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));
    init_graph(g, 5);
    add_edge(g, 0, 1, 1);
    add_edge(g, 0, 2, 2);
    add_edge(g, 0, 3, 3);
    add_edge(g, 1, 2, 4);
    add_edge(g, 1, 3, 5);
    add_edge(g, 2, 3, 6);
    remove_edge(g, 0, 1);
    remove_edge(g, 0, 2);
    print_graph(g);
    free_graph(g);
    return 0;
}