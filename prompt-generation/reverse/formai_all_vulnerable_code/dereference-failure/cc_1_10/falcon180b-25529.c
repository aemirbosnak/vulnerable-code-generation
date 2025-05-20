//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int vertex;
    int weight;
    struct edge *next;
} Edge;

typedef struct {
    int numVertices;
    int numEdges;
    int *vertices;
    Edge **edges;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->vertices = (int *) malloc(numVertices * sizeof(int));
    graph->edges = (Edge **) malloc(numVertices * sizeof(Edge *));
    for (int i = 0; i < numVertices; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int vertex1, int vertex2, int weight) {
    Edge *newEdge = (Edge *) malloc(sizeof(Edge));
    newEdge->vertex = vertex2;
    newEdge->weight = weight;
    newEdge->next = graph->edges[vertex1];
    graph->edges[vertex1] = newEdge;
    graph->numEdges++;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d:\n", i);
        Edge *edge = graph->edges[i];
        while (edge!= NULL) {
            printf("   Edge to vertex %d with weight %d\n", edge->vertex, edge->weight);
            edge = edge->next;
        }
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 4, 8);
    printGraph(graph);
    return 0;
}