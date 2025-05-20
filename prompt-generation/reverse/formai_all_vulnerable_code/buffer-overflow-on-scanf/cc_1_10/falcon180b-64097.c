//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 100
#define MAX_CHARS 20

typedef struct {
    char name[MAX_CHARS];
    int num_edges;
    int edges[MAX_EDGES];
} Node;

typedef struct {
    int src;
    int dest;
} Edge;

void addEdge(Node* nodes, int num_nodes, int src, int dest) {
    nodes[src].edges[nodes[src].num_edges++] = dest;
    nodes[dest].edges[nodes[dest].num_edges++] = src;
}

void printGraph(Node* nodes, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i, nodes[i].name);
        printf("Edges: ");
        for (int j = 0; j < nodes[i].num_edges; j++) {
            printf("%d ", nodes[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;
    char input[MAX_CHARS];
    while (true) {
        printf("Enter node name (or 'done' to finish): ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        strcpy(nodes[num_nodes].name, input);
        num_nodes++;
    }
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].num_edges = 0;
    }
    while (true) {
        printf("Enter edge (src dest): ");
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(nodes, num_nodes, src, dest);
    }
    printGraph(nodes, num_nodes);
    return 0;
}