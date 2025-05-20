//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int id;
    char name[50];
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void read_nodes(Node nodes[], int *num_nodes) {
    char buffer[50];
    printf("Enter the number of nodes: ");
    scanf("%d", num_nodes);

    for (int i = 0; i < *num_nodes; i++) {
        printf("Enter node %d name: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i+1;
    }
}

void read_edges(Edge edges[], int *num_edges) {
    printf("Enter the number of edges: ");
    scanf("%d", num_edges);

    for (int i = 0; i < *num_edges; i++) {
        printf("Enter edge %d details (src dest weight): ", i+1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
}

void print_nodes(Node nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_edges(Edge edges[], int num_edges) {
    for (int i = 0; i < num_edges; i++) {
        printf("(%d, %d, %d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes, num_edges;

    read_nodes(nodes, &num_nodes);
    read_edges(edges, &num_edges);

    printf("Nodes:\n");
    print_nodes(nodes, num_nodes);

    printf("\nEdges:\n");
    print_edges(edges, num_edges);

    return 0;
}