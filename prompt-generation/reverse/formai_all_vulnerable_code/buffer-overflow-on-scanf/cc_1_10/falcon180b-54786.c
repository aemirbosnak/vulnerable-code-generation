//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[20];
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void addEdge(Edge edges[], int numEdges, int src, int dest, int weight) {
    if (numEdges == MAX_EDGES) {
        printf("Error: Maximum number of edges reached\n");
        exit(1);
    }
    edges[numEdges].src = src;
    edges[numEdges].dest = dest;
    edges[numEdges].weight = weight;
    numEdges++;
}

void printGraph(Edge edges[], int numEdges, Node nodes[], int numNodes) {
    printf("Network Topology:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d -> %d (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

void main() {
    int numNodes, numEdges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter node %d name: ", i+1);
        scanf(" %[^\n]", nodes[i].name);
        nodes[i].id = i+1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge %d (src, dest, weight): ", i+1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    printGraph(edges, numEdges, nodes, numNodes);
}