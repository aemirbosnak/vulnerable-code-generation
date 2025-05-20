//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

void add_edge(Graph* g, int node1, int node2, int weight) {
    g->edges[g->num_edges].node1 = node1;
    g->edges[g->num_edges].node2 = node2;
    g->edges[g->num_edges].weight = weight;
    g->num_edges++;
}

int main() {
    int num_nodes, num_edges;
    int i, j, node1, node2, weight;

    // Get the number of nodes and edges from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    // Initialize the graph
    Graph g;
    g.num_nodes = num_nodes;
    g.num_edges = 0;

    // Get the edges from the user
    printf("Enter the edges (node1 node2 weight):\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &node1, &node2, &weight);
        add_edge(&g, node1, node2, weight);
    }

    // Print the graph
    printf("Graph:\n");
    for (i = 0; i < g.num_nodes; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < g.num_edges; i++) {
        printf("%d %d %d\n", g.edges[i].node1, g.edges[i].node2, g.edges[i].weight);
    }

    return 0;
}