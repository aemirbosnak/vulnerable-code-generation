//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 5000

typedef struct {
    int id;
    char name[20];
} Vertex;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    Vertex *vertices;
    Edge *edges;
    int numVertices;
    int numEdges;
} Graph;

Graph *createGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = (Vertex *)malloc(MAX_VERTICES * sizeof(Vertex));
    graph->edges = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
    graph->numVertices = 0;
    graph->numEdges = 0;
    return graph;
}

void addVertex(Graph *graph, char name[]) {
    Vertex vertex;
    strcpy(vertex.name, name);
    graph->vertices[graph->numVertices++] = vertex;
}

void addEdge(Graph *graph, int source, int destination, int weight) {
    Edge edge;
    edge.source = source;
    edge.destination = destination;
    edge.weight = weight;
    graph->edges[graph->numEdges++] = edge;
}

void printGraph(Graph *graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: %s\n", graph->vertices[i].id, graph->vertices[i].name);
    }
    printf("\n");
    for (int i = 0; i < graph->numEdges; i++) {
        printf("%d -> %d (%d)\n", graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main() {
    Graph *graph = createGraph();

    addVertex(graph, "A");
    addVertex(graph, "B");
    addVertex(graph, "C");
    addVertex(graph, "D");
    addVertex(graph, "E");

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 4, 8);

    printGraph(graph);

    return 0;
}