//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Graph structure definition
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Function to create a new graph with the given number of vertices
Graph* create_graph(int num_vertices) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->num_vertices = num_vertices;
    g->adjacency_list = (int*) malloc(num_vertices * sizeof(int));
    return g;
}

// Function to add an edge to the graph
void add_edge(Graph* g, int v1, int v2) {
    g->adjacency_list[v1] = (g->adjacency_list[v1] + 1) % (int) (g->num_vertices * 2);
    g->adjacency_list[g->adjacency_list[v1]] = v2;
}

// Function to print the graph
void print_graph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d:", i);
        for (int j = 0; j < g->adjacency_list[i]; j++) {
            printf(" %d", g->adjacency_list[i * (int) (g->num_vertices * 2) + j]);
        }
        printf("\n");
    }
}

// Function to traverse the graph using depth-first search
void dfs(Graph* g, int start) {
    int curr = start;
    int next = g->adjacency_list[curr];
    while (next != -1) {
        printf("%d ", curr);
        curr = next;
        next = g->adjacency_list[curr];
    }
    printf("\n");
}

int main() {
    Graph* g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    print_graph(g);
    dfs(g, 0);

    return 0;
}