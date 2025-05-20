//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NODES 50
#define MAX_EDGES 1000

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge edge[MAX_EDGES];
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

void printGraph(Graph* graph) {
    printf("\n\n Network Topology: \n\n");
    for (int i = 0; i < graph->E; i++) {
        printf("\tNode %d is connected to node %d with weight %d\n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    }
}

int main() {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Graph* graph = createGraph(n, m);


    for (int i = 0; i < m; i++) {
        printf("\n\n Enter the details of edge %d: \n\n", i+1);
        printf("Enter the source node: ");
        scanf("%d", &graph->edge[i].src);
        printf("Enter the destination node: ");
        scanf("%d", &graph->edge[i].dest);
        printf("Enter the weightage: ");
        scanf("%d", &graph->edge[i].weight);
    }

    printGraph(graph);

    return 0;
}