//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int id;
    char name[50];
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void addEdge(Edge edges[], int numEdges, int src, int dest, int weight) {
    if (numEdges == MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        return;
    }
    edges[numEdges].src = src;
    edges[numEdges].dest = dest;
    edges[numEdges].weight = weight;
    numEdges++;
}

int main() {
    int numNodes, numEdges = 0;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter the name of node %d: ", i + 1);
        scanf(" %[^\n]", nodes[i].name);
        nodes[i].id = i + 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        printf("Enter the source and destination nodes and weight for edge %d:\n", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(edges, numEdges, src, dest, weight);
    }

    printf("Network Topology:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d. %s\n", nodes[i].id, nodes[i].name);
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i == j)
                printf("%d ", 0);
            else if (i < j)
                printf("%d ", 1);
            else
                printf("%d ", 0);
        }
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; j < numEdges; j++) {
            if (edges[j].src == i + 1) {
                printf("%d ", edges[j].dest);
            }
        }
        printf("\n");
    }

    return 0;
}