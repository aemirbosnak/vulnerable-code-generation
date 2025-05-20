//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

typedef struct {
    int vertex;
    int weight;
    int next;
} Edge;

typedef struct {
    int *edges;
    int size;
} Graph;

void createGraph(Graph *graph) {
    int i;
    graph->size = 0;
    for (i = 0; i < MAX_VERTICES; ++i) {
        graph->edges[i] = NULL;
    }
}

void addEdge(Graph *graph, int vertex1, int vertex2, int weight) {
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = vertex2;
    newEdge->weight = weight;
    newEdge->next = graph->edges[vertex1];
    graph->edges[vertex1] = newEdge;
    graph->size += 1;
}

void printGraph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; ++i) {
        Edge *edge = graph->edges[i];
        if (edge == NULL) {
            printf("%d -> None\n", i);
            continue;
        }
        printf("%d -> ", i);
        while (edge!= NULL) {
            printf("%d ", edge->vertex);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);
    Graph graph;
    createGraph(&graph);
    int i;
    for (i = 0; i < numEdges; ++i) {
        int vertex1, vertex2, weight;
        scanf("%d %d %d", &vertex1, &vertex2, &weight);
        addEdge(&graph, vertex1, vertex2, weight);
    }
    printGraph(&graph);
    return 0;
}