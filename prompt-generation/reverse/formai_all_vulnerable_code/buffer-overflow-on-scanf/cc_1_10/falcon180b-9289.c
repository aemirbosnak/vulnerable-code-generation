//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

typedef struct {
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

void add_edge(Graph* graph, int node1, int node2, int weight) {
    Edge edge = {node1, node2, weight};
    graph->edges[graph->num_edges++] = edge;
}

void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_edges; i++) {
        printf("(%d, %d, %d)\n", graph->edges[i].node1, graph->edges[i].node2, graph->edges[i].weight);
    }
}

int main() {
    Graph graph = {0};
    int num_nodes, num_edges;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_nodes; i++) {
        char node_name[10];
        printf("Enter node name for node %d: ", i);
        scanf("%s", node_name);
        add_edge(&graph, i, -1, 0);
    }

    for (int i = 0; i < num_edges; i++) {
        int node1, node2, weight;
        printf("Enter edge %d (node1, node2, weight): ", i+1);
        scanf("%d%d%d", &node1, &node2, &weight);
        add_edge(&graph, node1, node2, weight);
    }

    print_graph(&graph);

    return 0;
}