//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge edges[MAX_EDGES];
} Network;

void add_edge(Network* net, int node1, int node2, int weight) {
    net->num_edges++;
    net->edges[net->num_edges-1].node1 = node1;
    net->edges[net->num_edges-1].node2 = node2;
    net->edges[net->num_edges-1].weight = weight;
}

void print_network(Network* net) {
    printf("Network with %d nodes and %d edges:\n", net->num_nodes, net->num_edges);
    for (int i = 0; i < net->num_edges; i++) {
        printf("Edge %d: (%d, %d) with weight %d\n", i+1, net->edges[i].node1, net->edges[i].node2, net->edges[i].weight);
    }
}

void map_network(Network* net) {
    int adj_matrix[MAX_NODES][MAX_NODES];
    memset(adj_matrix, 0, sizeof(adj_matrix));

    for (int i = 0; i < net->num_edges; i++) {
        adj_matrix[net->edges[i].node1][net->edges[i].node2] = net->edges[i].weight;
        adj_matrix[net->edges[i].node2][net->edges[i].node1] = net->edges[i].weight;
    }

    printf("Adjacency matrix:\n");
    for (int i = 0; i < net->num_nodes; i++) {
        for (int j = 0; j < net->num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Network net;
    net.num_nodes = 5;
    net.num_edges = 6;

    add_edge(&net, 0, 1, 2);
    add_edge(&net, 0, 3, 4);
    add_edge(&net, 1, 2, 1);
    add_edge(&net, 1, 4, 3);
    add_edge(&net, 2, 3, 1);
    add_edge(&net, 3, 4, 2);

    printf("Network:\n");
    print_network(&net);

    printf("\nAdjacency matrix:\n");
    map_network(&net);

    return 0;
}