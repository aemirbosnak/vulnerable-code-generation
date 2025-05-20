//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int id;
    char name[20];
    int degree;
    int *adjacent;
} Node;

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

Node *createNode(int id, char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    strcpy(node->name, name);
    node->degree = 0;
    node->adjacent = (int *)malloc(MAX_EDGES * sizeof(int));
    return node;
}

void addEdge(Node *graph, int u, int v, int weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->u = u;
    edge->v = v;
    edge->weight = weight;
    graph->adjacent[graph->degree++] = v;
}

void printGraph(Node *graph) {
    printf("Node %d (%s) has %d edges:\n", graph->id, graph->name, graph->degree);
    for (int i = 0; i < graph->degree; i++) {
        printf("  Edge %d -> %d with weight %d\n", graph->id, graph->adjacent[i], INF);
    }
}

int main() {
    Node *graph[MAX_NODES];
    int numNodes = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        char name[20];
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", name);
        graph[i] = createNode(i+1, name);
    }

    printf("Enter the edges (u v weight):\n");
    Edge edge;
    while (scanf("%d %d %d", &edge.u, &edge.v, &edge.weight) == 3) {
        addEdge(graph[edge.u-1], edge.u, edge.v, edge.weight);
    }

    for (int i = 0; i < numNodes; i++) {
        printGraph(graph[i]);
    }

    return 0;
}