//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    char name[20];
    int id;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void addEdge(Edge edges[], int numEdges, int src, int dest, int weight) {
    if (numEdges == MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(0);
    }

    edges[numEdges].src = src;
    edges[numEdges].dest = dest;
    edges[numEdges].weight = weight;
    numEdges++;
}

void printGraph(Edge edges[], int numEdges) {
    printf("Graph:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d -> %d (weight: %d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    int numNodes, numEdges;
    scanf("%d %d", &numNodes, &numEdges);

    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    numEdges = 0;

    for (int i = 0; i < numNodes; i++) {
        scanf("%s", nodes[i].name);
        nodes[i].id = i;
    }

    int src, dest, weight;
    while (numEdges < MAX_EDGES && scanf("%d %d %d", &src, &dest, &weight) == 3) {
        addEdge(edges, numEdges, src, dest, weight);
    }

    printGraph(edges, numEdges);

    return 0;
}