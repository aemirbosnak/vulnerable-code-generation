//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 2000

typedef struct {
    int id;
    char name[50];
} Vertex;

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

int numVertices = 0;
int numEdges = 0;

Vertex* vertices = NULL;
Edge* edges = NULL;

void addVertex(char* name) {
    Vertex* newVertex = (Vertex*) malloc(sizeof(Vertex));
    strcpy(newVertex->name, name);
    newVertex->id = numVertices++;
    vertices = (Vertex*) realloc(vertices, sizeof(Vertex) * numVertices);
    vertices[numVertices - 1] = *newVertex;
}

void addEdge(int from, int to, int weight) {
    Edge* newEdge = (Edge*) malloc(sizeof(Edge));
    newEdge->from = from;
    newEdge->to = to;
    newEdge->weight = weight;
    edges = (Edge*) realloc(edges, sizeof(Edge) * numEdges + 1);
    edges[numEdges++] = *newEdge;
}

void printGraph() {
    printf("The graph has %d vertices and %d edges:\n", numVertices, numEdges);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: %s\n", i, vertices[i].name);
    }
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: (%d, %d, %d)\n", i, edges[i].from, edges[i].to, edges[i].weight);
    }
}

int main() {
    addVertex("A");
    addVertex("B");
    addVertex("C");
    addVertex("D");
    addVertex("E");
    addEdge(0, 1, 5);
    addEdge(1, 2, 10);
    addEdge(2, 3, 15);
    addEdge(3, 4, 20);
    addEdge(4, 0, 25);
    printGraph();
    return 0;
}