//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

// Graph structure
typedef struct node {
    int id;
    int num_neighbors;
    int *neighbors;
    int color;
} Node;

// Graph representation
Node *graph;
int num_nodes;
int num_edges;

// Helper functions
void init_graph(int num_nodes) {
    graph = (Node*) malloc(sizeof(Node) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph[i].id = i;
        graph[i].num_neighbors = 0;
        graph[i].neighbors = NULL;
        graph[i].color = -1;
    }
}

void add_edge(int u, int v) {
    graph[u].neighbors = (int*) realloc(graph[u].neighbors, sizeof(int) * ++graph[u].num_neighbors);
    graph[u].neighbors[graph[u].num_neighbors - 1] = v;
    graph[v].neighbors = (int*) realloc(graph[v].neighbors, sizeof(int) * ++graph[v].num_neighbors);
    graph[v].neighbors[graph[v].num_neighbors - 1] = u;
}

void print_graph() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < graph[i].num_neighbors; j++) {
            printf("%d ", graph[i].neighbors[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL));
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % (num_nodes * (num_nodes - 1) / 2) + 1;

    init_graph(num_nodes);

    for (int i = 0; i < num_edges; i++) {
        int u = rand() % num_nodes;
        int v = rand() % num_nodes;
        while (u == v) {
            v = rand() % num_nodes;
        }
        add_edge(u, v);
    }

    print_graph();

    return 0;
}