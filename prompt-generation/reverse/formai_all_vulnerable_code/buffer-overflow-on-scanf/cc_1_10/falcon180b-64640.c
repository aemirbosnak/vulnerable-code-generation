//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int vertex;
    int color;
} Edge;

void printGraph(Edge *graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        printf("%d - ", i);
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i * numVertices + j].vertex!= -1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

int isValid(int *colors, int numVertices, int vertex, int color) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(Edge *graph, int numVertices, int *colors) {
    int vertex = 0;
    while (vertex < numVertices) {
        int color = rand() % MAX_COLORS;
        while (!isValid(colors, numVertices, vertex, color)) {
            color = rand() % MAX_COLORS;
        }
        colors[vertex] = color;
        vertex++;
    }
}

int main() {
    srand(time(NULL));
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    Edge *graph = (Edge *) malloc(numVertices * numVertices * sizeof(Edge));
    int *colors = (int *) malloc(numVertices * sizeof(int));
    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1 * numVertices + vertex2].vertex = vertex2;
        graph[vertex2 * numVertices + vertex1].vertex = vertex1;
    }
    colorGraph(graph, numVertices, colors);
    printf("The colored graph:\n");
    printGraph(graph, numVertices);
    free(graph);
    free(colors);
    return 0;
}