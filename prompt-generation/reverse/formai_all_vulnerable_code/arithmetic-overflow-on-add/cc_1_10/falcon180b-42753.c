//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    char name[20];
    int degree;
    int *adj;
} Node;

Node createNode(char name[], int degree) {
    Node node;
    strcpy(node.name, name);
    node.degree = degree;
    node.adj = (int *)malloc(degree * sizeof(int));
    return node;
}

void addEdge(Node *graph, int u, int v) {
    graph[u].adj[graph[u].degree++] = v;
    graph[v].adj[graph[v].degree++] = u;
}

void printGraph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %s: ", graph[i].name);
        for (int j = 0; j < graph[i].degree; j++) {
            printf("%d ", graph[i].adj[j]);
        }
        printf("\n");
    }
}

int main() {
    Node graph[MAX_NODES];
    int n = 0;

    // Create nodes
    Node node1 = createNode("A", 2);
    Node node2 = createNode("B", 2);
    Node node3 = createNode("C", 2);
    Node node4 = createNode("D", 2);
    Node node5 = createNode("E", 2);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print graph
    printf("Graph representation:\n");
    printGraph(graph, n);

    return 0;
}