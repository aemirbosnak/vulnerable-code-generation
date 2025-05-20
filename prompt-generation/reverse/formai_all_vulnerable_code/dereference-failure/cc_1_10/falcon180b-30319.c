//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_VERTICES 200

typedef struct edge {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct node {
    int id;
    int degree;
    Edge *edges;
} Node;

void addEdge(Node *graph, int src, int dest, int weight) {
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->weight = weight;

    graph[src].edges = (Edge*)realloc(graph[src].edges, sizeof(Edge) * (graph[src].degree + 1));
    graph[src].edges[graph[src].degree++] = *newEdge;
}

void printGraph(Node *graph, int nodes) {
    for (int i = 0; i < nodes; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < graph[i].degree; j++) {
            printf("(%d,%d,%d) ", graph[i].edges[j].src, graph[i].edges[j].dest, graph[i].edges[j].weight);
        }
        printf("\n");
    }
}

int main() {
    Node *graph = (Node*)malloc(sizeof(Node) * MAX_NODES);
    int nodes = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        graph[i].id = i;
        graph[i].degree = 0;
        graph[i].edges = NULL;
    }

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 10);
    addEdge(graph, 1, 2, 15);
    addEdge(graph, 2, 3, 20);
    addEdge(graph, 3, 4, 15);
    addEdge(graph, 4, 5, 10);

    printGraph(graph, nodes);

    return 0;
}