//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 6

typedef struct {
    int vertex;
    int color;
} GraphNode;

typedef struct {
    int numVertices;
    GraphNode *nodes;
} Graph;

void createGraph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph->nodes[i].vertex = i;
        graph->nodes[i].color = 0;
    }
}

void printGraph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: %d\n", i, graph->nodes[i].color);
    }
}

int isSafe(Graph *graph, int color, int vertex) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (graph->nodes[i].color == color && graph->nodes[i].vertex!= vertex) {
            return 0;
        }
    }
    return 1;
}

int colorGraph(Graph *graph) {
    int i, j, k;
    int colors[MAX_COLORS] = {1, 2, 3, 4, 5, 6};
    int numColors = 6;
    int numVertices = graph->numVertices;
    int *colorMap = (int *)malloc(numVertices * sizeof(int));
    for (i = 0; i < numVertices; i++) {
        colorMap[i] = 0;
    }
    for (i = 0; i < numVertices; i++) {
        int vertex = i;
        int color = 1;
        while (!isSafe(graph, color, vertex)) {
            color++;
            if (color == numColors) {
                color = 1;
            }
        }
        colorMap[vertex] = color;
    }
    for (i = 0; i < numVertices; i++) {
        graph->nodes[i].color = colorMap[i];
    }
    free(colorMap);
    return 1;
}

int main() {
    int i;
    srand(time(0));
    Graph graph;
    createGraph(&graph);
    colorGraph(&graph);
    printGraph(&graph);
    return 0;
}