//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

typedef struct {
    int x, y;
} Point;

typedef struct {
    int u, v;
} Edge;

typedef struct {
    int n;
    Point vertices[MAX_VERTICES];
    Edge edges[MAX_EDGES];
} Graph;

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    for (int i = 0; i < n; i++) {
        graph->vertices[i].x = rand() % 100;
        graph->vertices[i].y = rand() % 100;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    Edge edge = {u, v};
    graph->edges[graph->n++] = edge;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        printf("(%d,%d) ", graph->vertices[i].x, graph->vertices[i].y);
    }
    printf("\n");
}

int main() {
    int n = 10;
    Graph* graph = createGraph(n);
    for (int i = 0; i < n - 1; i++) {
        int u = rand() % n;
        int v = rand() % n;
        while (u == v) {
            v = rand() % n;
        }
        addEdge(graph, u, v);
    }
    printf("Graph representation:\n");
    printGraph(graph);
    return 0;
}