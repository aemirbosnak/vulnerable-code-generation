//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 100

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

int read_nodes(FILE* fp, int* nodes, int max_nodes) {
    int count = 0;
    while (fscanf(fp, "%d", nodes + count)!= EOF) {
        count++;
        if (count >= max_nodes) {
            break;
        }
    }
    return count;
}

int read_edges(FILE* fp, Edge* edges, int max_edges) {
    int count = 0;
    while (fscanf(fp, "%d %d %d", &edges[count].node1, &edges[count].node2, &edges[count].weight)!= EOF) {
        count++;
        if (count >= max_edges) {
            break;
        }
    }
    return count;
}

void print_network(Network* network) {
    printf("Number of nodes: %d\n", network->num_nodes);
    printf("Number of edges: %d\n", network->num_edges);
    for (int i = 0; i < network->num_edges; i++) {
        printf("%d -> %d, weight: %d\n", network->edges[i].node1, network->edges[i].node2, network->edges[i].weight);
    }
}

int main() {
    FILE* fp = fopen("network.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int nodes[MAX_NODES];
    int num_nodes = read_nodes(fp, nodes, MAX_NODES);
    if (num_nodes <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    Network network;
    network.num_nodes = num_nodes;
    network.num_edges = read_edges(fp, network.edges, MAX_EDGES);
    if (network.num_edges <= 0) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    print_network(&network);

    fclose(fp);
    return 0;
}