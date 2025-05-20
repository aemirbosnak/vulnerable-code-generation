//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    char name[20];
    int id;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

void addEdge(Edge edges[], int numEdges, int source, int destination, int weight) {
    if (numEdges >= MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    edges[numEdges].source = source;
    edges[numEdges].destination = destination;
    edges[numEdges].weight = weight;
    numEdges++;
}

void printEdges(Edge edges[], int numEdges) {
    printf("Edges:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%d -> %d (%d)\n", edges[i].source, edges[i].destination, edges[i].weight);
    }
}

int main() {
    int numNodes, numEdges;
    char input[100];
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the names and IDs of the nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].id = i+1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: ", i+1);
        scanf("%s", input);
        int source, destination, weight;
        sscanf(input, "%d %d %d", &source, &destination, &weight);
        addEdge(edges, numEdges, source, destination, weight);
    }

    printEdges(edges, numEdges);

    return 0;
}