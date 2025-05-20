//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (numEdges >= MAX_EDGES) {
        printf("Maximum number of edges reached.\n");
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
        scanf("%s", nodes[i].name);
        nodes[i].id = i + 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter the source node ID: ");
        int src;
        scanf("%d", &src);

        printf("Enter the destination node ID: ");
        int dest;
        scanf("%d", &dest);

        printf("Enter the weight of the edge: ");
        int weight;
        scanf("%d", &weight);

        addEdge(edges, numEdges, src, dest, weight);
    }

    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
    }

    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: (%d, %d, %d)\n", i + 1, edges[i].src, edges[i].dest, edges[i].weight);
    }

    return 0;
}