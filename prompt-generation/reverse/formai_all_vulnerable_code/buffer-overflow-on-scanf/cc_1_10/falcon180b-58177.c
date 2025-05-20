//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
    int num_edges;
    int edges[MAX_EDGES];
} Node;

int main() {
    int num_nodes, num_edges;
    Node nodes[MAX_NODES];
    int i, j, k, edge_id;
    char input[100];

    // Read the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    // Read the node details
    for (i = 0; i < num_nodes; i++) {
        printf("Enter the details of node %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &nodes[i].id);
        printf("Name: ");
        scanf("%s", nodes[i].name);
        printf("Number of edges: ");
        scanf("%d", &nodes[i].num_edges);
    }

    // Read the edges
    printf("\nEnter the edges (node1 node2 weight):\n");
    num_edges = 0;
    while (num_edges < MAX_EDGES && scanf("%s", input)!= EOF) {
        if (num_edges == MAX_EDGES) {
            printf("Error: Maximum number of edges reached.\n");
            exit(1);
        }
        sscanf(input, "%d %d %d", &edge_id, &i, &j);
        nodes[i-1].edges[nodes[i-1].num_edges++] = edge_id;
        nodes[j-1].edges[nodes[j-1].num_edges++] = edge_id;
        num_edges++;
    }

    // Print the topology
    printf("\nNetwork Topology:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
        printf("Edges: ");
        for (j = 0; j < nodes[i].num_edges; j++) {
            printf("%d ", nodes[i].edges[j]);
        }
        printf("\n");
    }

    return 0;
}