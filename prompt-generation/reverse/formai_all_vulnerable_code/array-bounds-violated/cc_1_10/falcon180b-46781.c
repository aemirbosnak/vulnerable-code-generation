//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_EDGE_LENGTH 10

int num_nodes;
int num_edges;
int adj_matrix[MAX_NODES][MAX_NODES];

void add_edge(int node1, int node2) {
    adj_matrix[node1][node2] = 1;
    adj_matrix[node2][node1] = 1;
    num_edges++;
}

void print_adj_matrix() {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Network Topology Mapper!\n");
    printf("Please enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Please enter the name of node %d: ", i+1);
        char name[MAX_EDGE_LENGTH];
        scanf("%s", name);
        printf("Node %s added to the network.\n", name);
    }

    printf("Please enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Please enter the edges (format: node1 node2):\n");
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        add_edge(node1, node2);
    }

    printf("The adjacency matrix of the network is:\n");
    print_adj_matrix();

    return 0;
}