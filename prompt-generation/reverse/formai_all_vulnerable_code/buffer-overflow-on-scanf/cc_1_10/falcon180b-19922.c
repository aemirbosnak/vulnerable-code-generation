//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define NODE_NAME_LEN 20
#define EDGE_NAME_LEN 30

typedef struct {
    int id;
    char name[NODE_NAME_LEN];
    int num_edges;
    int edges[MAX_EDGES];
} Node;

typedef struct {
    int id;
    char name[EDGE_NAME_LEN];
    int node1_id;
    int node2_id;
} Edge;

void read_nodes(Node nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter node %d name: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i;
    }
}

void read_edges(Edge edges[], int num_edges) {
    for (int i = 0; i < num_edges; i++) {
        printf("Enter edge %d name: ", i+1);
        scanf("%s", edges[i].name);
        printf("Enter node 1 ID: ");
        scanf("%d", &edges[i].node1_id);
        printf("Enter node 2 ID: ");
        scanf("%d", &edges[i].node2_id);
    }
}

void print_nodes(Node nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_edges(Edge edges[], int num_edges) {
    for (int i = 0; i < num_edges; i++) {
        printf("%s: %d -> %d\n", edges[i].name, edges[i].node1_id, edges[i].node2_id);
    }
}

int main() {
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    int num_nodes, num_edges;

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    read_nodes(nodes, num_nodes);
    read_edges(edges, num_edges);

    printf("Node list:\n");
    print_nodes(nodes, num_nodes);

    printf("\nEdge list:\n");
    print_edges(edges, num_edges);

    return 0;
}