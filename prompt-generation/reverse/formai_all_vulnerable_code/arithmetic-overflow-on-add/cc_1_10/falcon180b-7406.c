//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int id;
    char name[20];
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

int nodeCount = 0;
int edgeCount = 0;

void addNode(int id, char* name) {
    nodes[nodeCount].id = id;
    strcpy(nodes[nodeCount].name, name);
    nodeCount++;
}

void addEdge(int src, int dest, int weight) {
    edges[edgeCount].src = src;
    edges[edgeCount].dest = dest;
    edges[edgeCount].weight = weight;
    edgeCount++;
}

void printNodes() {
    printf("Nodes:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%d - %s\n", nodes[i].id, nodes[i].name);
    }
}

void printEdges() {
    printf("\nEdges:\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("%d -> %d (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

void mapNetwork() {
    int start, end, weight;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);
    for (int i = 0; i < nodeCount; i++) {
        printf("Enter the ID and name of node %d: ", i+1);
        scanf("%d %s", &start, nodes[i].name);
        nodes[i].id = start;
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edgeCount);
    for (int i = 0; i < edgeCount; i++) {
        printf("Enter the start and end nodes and weight for edge %d: ", i+1);
        scanf("%d %d %d", &start, &end, &weight);
        addEdge(start, end, weight);
    }
}

int main() {
    mapNetwork();
    printNodes();
    printEdges();
    return 0;
}