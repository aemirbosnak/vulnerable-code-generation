//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

typedef struct {
    int vertex;
    int weight;
    struct Edge *next;
} Edge;

typedef struct {
    int vertices;
    Edge *edges[MAX_VERTICES];
} Graph;

Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    int i;
    for (i = 0; i < vertices; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int start, int end, int weight) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->vertex = end;
    newEdge->weight = weight;
    newEdge->next = NULL;
    Edge *currEdge = graph->edges[start];
    if (currEdge == NULL) {
        graph->edges[start] = newEdge;
    } else {
        while (currEdge->next!= NULL) {
            currEdge = currEdge->next;
        }
        currEdge->next = newEdge;
    }
}

void printGraph(Graph *graph) {
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Edge *currEdge = graph->edges[i];
        printf("Vertex %d: ", i);
        while (currEdge!= NULL) {
            printf("(%d,%d) ", currEdge->vertex, currEdge->weight);
            currEdge = currEdge->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);
    Graph *graph = createGraph(vertices);
    int i;
    for (i = 0; i < edges; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        addEdge(graph, start, end, weight);
    }
    printGraph(graph);
    return 0;
}