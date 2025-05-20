//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name[20];
    int degree;
    int *neighbors;
} Node;

void addNode(Node *nodes, int numNodes, char *name) {
    int i;
    for (i = 0; i < numNodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            printf("Node %s already exists!\n", name);
            return;
        }
    }
    strcpy(nodes[numNodes].name, name);
    nodes[numNodes].degree = 0;
    nodes[numNodes].neighbors = (int *)malloc(MAX_EDGES * sizeof(int));
    numNodes++;
}

void addEdge(Node *nodes, int numEdges, int u, int v) {
    nodes[u].degree++;
    int *neighbors = nodes[u].neighbors;
    int k = 0;
    while (k < nodes[u].degree && neighbors[k]!= v) {
        k++;
    }
    if (k == nodes[u].degree) {
        neighbors[k] = v;
        nodes[u].degree++;
    }
}

void printGraph(Node *nodes, int numNodes) {
    int i;
    for (i = 0; i < numNodes; i++) {
        printf("Node %s has degree %d and neighbors: ", nodes[i].name, nodes[i].degree);
        int *neighbors = nodes[i].neighbors;
        int j;
        for (j = 0; j < nodes[i].degree; j++) {
            printf("%d ", neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    Node nodes[MAX_NODES];
    int numNodes = 0;
    int numEdges = 0;

    addNode(nodes, numNodes, "A");
    addNode(nodes, numNodes, "B");
    addNode(nodes, numNodes, "C");
    addNode(nodes, numNodes, "D");
    addNode(nodes, numNodes, "E");

    addEdge(nodes, numEdges, 0, 1);
    addEdge(nodes, numEdges, 0, 2);
    addEdge(nodes, numEdges, 1, 3);
    addEdge(nodes, numEdges, 2, 1);
    addEdge(nodes, numEdges, 2, 3);
    addEdge(nodes, numEdges, 3, 4);

    printGraph(nodes, numNodes);

    return 0;
}