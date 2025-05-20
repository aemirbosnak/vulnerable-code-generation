//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_WEIGHT 1000

// Node structure
typedef struct {
    int id;
    char name[20];
} Node;

// Edge structure
typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void addEdge(Edge edges[], int n, int src, int dest, int weight) {
    if (n == MAX_EDGES) {
        printf("Sorry, maximum number of edges reached!\n");
        return;
    }
    edges[n].src = src;
    edges[n].dest = dest;
    edges[n].weight = weight;
    n++;
}

void printEdges(Edge edges[], int n) {
    printf("Edges:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

void addNode(Node nodes[], int n, int id, char name[]) {
    if (n == MAX_NODES) {
        printf("Sorry, maximum number of nodes reached!\n");
        return;
    }
    nodes[n].id = id;
    strcpy(nodes[n].name, name);
    n++;
}

void printNodes(Node nodes[], int n) {
    printf("Nodes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", nodes[i].id, nodes[i].name);
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Node nodes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the ID and name of node %d: ", i+1);
        scanf("%d %s", &nodes[i].id, nodes[i].name);
    }
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    Edge edges[m];
    for (int i = 0; i < m; i++) {
        printf("Enter the source and destination nodes and weight of edge %d: ", i+1);
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(edges, 0, src, dest, weight);
    }
    printNodes(nodes, n);
    printEdges(edges, m);
    return 0;
}