//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

struct graph_t {
    int num_nodes;
    int num_edges;
    int *adj_list;
};

int add_edge(struct graph_t *graph, int u, int v) {
    if (graph->num_nodes == MAX_NODES) {
        return -1; // graph is full
    }
    if (graph->adj_list[u] == MAX_EDGES) {
        return -2; // edge list for u is full
    }
    graph->adj_list[u]++;
    graph->adj_list[graph->adj_list[u] - 1] = v;
    return 0;
}

void print_adj_list(struct graph_t *graph, int node) {
    printf("%d ", node);
    for (int i = 0; i < graph->adj_list[node]; i++) {
        printf("%d ", graph->adj_list[graph->adj_list[node] - 1 + i]);
    }
    printf("\n");
}

int main() {
    struct graph_t graph;
    graph.num_nodes = 0;
    graph.num_edges = 0;
    graph.adj_list = malloc(MAX_NODES * sizeof(int));

    int n, m, u, v;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        add_edge(&graph, i, -1); // add self-loop for every node
    }

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Enter the edges: ");
        scanf("%d %d", &u, &v);
        add_edge(&graph, u, v);
    }

    printf("Adjacency list for the graph:\n");
    for (int i = 0; i < n; i++) {
        print_adj_list(&graph, i);
    }

    return 0;
}