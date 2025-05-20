//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int node1;
    int node2;
    int weight;
} Edge;

void addEdge(Edge edges[], int numEdges, int node1, int node2, int weight) {
    if(numEdges == MAX_EDGES) {
        printf("Error: Maximum number of edges reached.\n");
        exit(1);
    }
    edges[numEdges].node1 = node1;
    edges[numEdges].node2 = node2;
    edges[numEdges].weight = weight;
    numEdges++;
}

void printGraph(Edge edges[], int numEdges) {
    printf("Graph:\n");
    for(int i=0; i<numEdges; i++) {
        printf("%d - %d (%d)\n", edges[i].node1, edges[i].node2, edges[i].weight);
    }
}

int main() {
    int numNodes, numEdges;
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    Edge edges[MAX_EDGES];
    memset(edges, 0, sizeof(Edge) * MAX_EDGES);

    printf("Enter edges (node1 node2 weight):\n");
    for(int i=0; i<numEdges; i++) {
        int node1, node2, weight;
        scanf("%d %d %d", &node1, &node2, &weight);
        addEdge(edges, numEdges, node1, node2, weight);
    }

    printGraph(edges, numEdges);

    return 0;
}