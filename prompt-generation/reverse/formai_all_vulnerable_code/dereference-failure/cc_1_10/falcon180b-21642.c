//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *vertices;
    int numVertices;
    int **edges;
    int numEdges;
} Graph;

Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = (Point *)malloc(numVertices * sizeof(Point));
    graph->numVertices = numVertices;
    graph->edges = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph->edges[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    graph->numEdges = 0;
    return graph;
}

void addEdge(Graph *graph, int vertex1, int vertex2) {
    graph->edges[vertex1][vertex2] = 1;
    graph->edges[vertex2][vertex1] = 1;
    graph->numEdges++;
}

void deleteGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->edges[i]);
    }
    free(graph->edges);
    free(graph->vertices);
    free(graph);
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: (%d, %d)\n", i, graph->vertices[i].x, graph->vertices[i].y);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf("Edge to vertex %d\n", j);
            }
        }
    }
}

int main() {
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    deleteGraph(graph);
    return 0;
}