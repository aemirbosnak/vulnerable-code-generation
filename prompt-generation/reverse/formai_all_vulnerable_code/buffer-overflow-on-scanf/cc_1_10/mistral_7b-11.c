//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int* vertexColor;
} Graph;

void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
        graph->vertexColor[i] = MIN_COLOR;
    }
}

void addEdge(Graph* graph, int vertex1, int vertex2) {
    graph->adjMatrix[vertex1][vertex2] = 1;
    graph->adjMatrix[vertex2][vertex1] = 1;
}

bool isSafeToColor(Graph* graph, int vertex, int color) {
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjMatrix[vertex][i] && graph->vertexColor[i] == color) {
            return false;
        }
    }
    return true;
}

void graphColoringUtil(Graph* graph, int vertex, int color) {
    graph->vertexColor[vertex] = color;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjMatrix[vertex][i] && !isSafeToColor(graph, i, color)) {
            graph->vertexColor[vertex] = MIN_COLOR;
            return;
        }
    }

    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->adjMatrix[i][vertex] && graph->vertexColor[i] == MIN_COLOR) {
            graphColoringUtil(graph, i, color);
        }
    }
}

void graphColoring(Graph* graph) {
    int m = 0;
    for (int i = 0; i < graph->numVertices; ++i) {
        if (graph->vertexColor[i] == MIN_COLOR) {
            bool success = false;
            for (int color = MIN_COLOR; color <= MAX_COLOR; ++color) {
                if (isSafeToColor(graph, i, color)) {
                    graphColoringUtil(graph, i, color);
                    m = (m >= color) ? m : color;
                    success = true;
                    break;
                }
            }
            if (!success) {
                printf("Graph cannot be colored with given colors.\n");
                return;
            }
        }
    }

    printf("Graph can be colored with %d colors.\n", m + 1);
}

int main() {
    int numVertices, vertex1, vertex2;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph graph;
    initializeGraph(&graph, numVertices);

    printf("Enter the number of edges and their vertices:\n");
    for (int i = 0; i < numVertices * (numVertices - 1) / 2; ++i) {
        scanf("%d%d", &vertex1, &vertex2);
        addEdge(&graph, vertex1, vertex2);
    }

    graphColoring(&graph);

    return 0;
}