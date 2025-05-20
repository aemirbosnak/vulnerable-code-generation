//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200

struct Node {
    int id;
    int degree;
    int *neighbors;
};

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int n;
    int m;
    struct Node *nodes;
    struct Edge *edges;
};

void createGraph(struct Graph *graph) {
    graph->n = 0;
    graph->m = 0;
    graph->nodes = NULL;
    graph->edges = NULL;
}

void addNode(struct Graph *graph, int id) {
    graph->n++;
    graph->nodes = realloc(graph->nodes, sizeof(struct Node) * graph->n);
    graph->nodes[graph->n-1].id = id;
    graph->nodes[graph->n-1].degree = 0;
    graph->nodes[graph->n-1].neighbors = NULL;
}

void addEdge(struct Graph *graph, int src, int dest, int weight) {
    graph->m++;
    graph->edges = realloc(graph->edges, sizeof(struct Edge) * graph->m);
    graph->edges[graph->m-1].src = src;
    graph->edges[graph->m-1].dest = dest;
    graph->edges[graph->m-1].weight = weight;
    graph->nodes[src-1].degree++;
    graph->nodes[src-1].neighbors = realloc(graph->nodes[src-1].neighbors, sizeof(int) * graph->nodes[src-1].degree);
    graph->nodes[src-1].neighbors[graph->nodes[src-1].degree-1] = dest;
}

void printGraph(struct Graph *graph) {
    int i, j;
    for(i=0; i<graph->n; i++) {
        printf("Node %d: ", graph->nodes[i].id);
        for(j=0; j<graph->nodes[i].degree; j++) {
            printf("%d ", graph->nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    createGraph(&graph);
    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addEdge(&graph, 1, 2, 3);
    addEdge(&graph, 2, 3, 2);
    addEdge(&graph, 3, 1, 4);
    printGraph(&graph);
    return 0;
}