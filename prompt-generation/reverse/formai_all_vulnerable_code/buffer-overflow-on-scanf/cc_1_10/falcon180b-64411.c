//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

// Node structure to store node name and its edges
typedef struct {
    char name[20];
    int num_edges;
    int edges[MAX_EDGES];
} Node;

// Function to add an edge between two nodes
void add_edge(Node* nodes, int node1, int node2) {
    nodes[node1].edges[nodes[node1].num_edges++] = node2;
    nodes[node2].edges[nodes[node2].num_edges++] = node1;
}

// Function to print the adjacency list of a node
void print_adjacency_list(Node* nodes, int node) {
    printf("Adjacency list of %s:\n", nodes[node].name);
    for (int i = 0; i < nodes[node].num_edges; i++) {
        printf("%s ", nodes[nodes[node].edges[i]].name);
    }
    printf("\n");
}

// Function to display the network topology
void display_network_topology(Node* nodes, int num_nodes) {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i + 1, nodes[i].name);
        print_adjacency_list(nodes, i);
    }
}

// Main function to read input and create the network topology
int main() {
    int num_nodes, num_edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    Node* nodes = (Node*) malloc(num_nodes * sizeof(Node));
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf("%s", nodes[i].name);
        nodes[i].num_edges = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    int node1, node2;
    for (int i = 0; i < num_edges; i++) {
        printf("Enter the two nodes for edge %d: ", i + 1);
        scanf("%d %d", &node1, &node2);
        add_edge(nodes, node1 - 1, node2 - 1);
    }

    display_network_topology(nodes, num_nodes);

    return 0;
}