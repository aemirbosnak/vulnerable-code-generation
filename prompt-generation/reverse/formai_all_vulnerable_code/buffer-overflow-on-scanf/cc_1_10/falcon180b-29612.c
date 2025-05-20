//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define MAX_NAME_LENGTH 20
#define MAX_IP_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
} Node;

typedef struct {
    Node node1;
    Node node2;
    int weight;
} Edge;

void add_node(Node* node, int count) {
    printf("Enter the name of node %d: ", count);
    scanf("%s", node->name);
    printf("Enter the IP address of node %d: ", count);
    scanf("%s", node->ip);
}

void add_edge(Edge* edge, int count) {
    printf("Enter the name of node 1 for edge %d: ", count);
    scanf("%s", edge->node1.name);
    printf("Enter the IP address of node 1 for edge %d: ", count);
    scanf("%s", edge->node1.ip);

    printf("Enter the name of node 2 for edge %d: ", count);
    scanf("%s", edge->node2.name);
    printf("Enter the IP address of node 2 for edge %d: ", count);
    scanf("%s", edge->node2.ip);

    printf("Enter the weight of edge %d: ", count);
    scanf("%d", &edge->weight);
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes, num_edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        add_node(&nodes[i], i);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        add_edge(&edges[i], i);
    }

    // Map network topology here

    return 0;
}