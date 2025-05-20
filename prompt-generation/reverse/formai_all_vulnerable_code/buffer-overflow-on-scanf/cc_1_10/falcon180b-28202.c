//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    char name[10];
    int id;
} Node;

typedef struct edge {
    int source;
    int destination;
    int weight;
} Edge;

int num_nodes = 0;
int num_edges = 0;
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

void add_node(char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        exit(1);
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].id = num_nodes;
    num_nodes++;
}

void add_edge(int source, int destination, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    edges[num_edges].source = source;
    edges[num_edges].destination = destination;
    edges[num_edges].weight = weight;
    num_edges++;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d. %s\n", i, nodes[i].name);
    }
}

void print_edges() {
    printf("Edges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].source, edges[i].destination, edges[i].weight);
    }
}

int main() {
    char name[10];
    int source, destination, weight;

    printf("Enter the number of nodes:\n");
    scanf("%d", &num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name of node %d:\n", i);
        scanf("%s", name);
        add_node(name);
    }

    printf("Enter the number of edges:\n");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter the source node ID for edge %d:\n", i);
        scanf("%d", &source);
        printf("Enter the destination node ID for edge %d:\n", i);
        scanf("%d", &destination);
        printf("Enter the weight for edge %d:\n", i);
        scanf("%d", &weight);
        add_edge(source, destination, weight);
    }

    print_nodes();
    print_edges();

    return 0;
}