//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void printGraph(int **graph, int numVertices);
int graphColoring(int **graph, int numVertices, int numColors, int *colorArr);

int main() {
    int numVertices, numEdges, numColors;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    int **graph = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        graph[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    printf("Enter number of colors: ");
    scanf("%d", &numColors);
    int *colorArr = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        colorArr[i] = 0;
    }

    printf("\nGraph:\n");
    printGraph(graph, numVertices);

    if (graphColoring(graph, numVertices, numColors, colorArr) == 0) {
        printf("Solution does not exist");
    } else {
        printf("Solution exists, and the coloring is:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d -> Color %d\n", i, colorArr[i]);
        }
    }

    return 0;
}

void printGraph(int **graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int canColor(int vertex, int **graph, int numVertices, int *colorArr, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && color == colorArr[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(int **graph, int numVertices, int numColors, int *colorArr, int vertex) {
    if (vertex == numVertices) {
        return 1;
    }

    for (int i = 1; i <= numColors; i++) {
        if (canColor(vertex, graph, numVertices, colorArr, i)) {
            colorArr[vertex] = i;
            if (graphColoringUtil(graph, numVertices, numColors, colorArr, vertex + 1) == 1) {
                return 1;
            }
            colorArr[vertex] = 0;
        }
    }
    return 0;
}

int graphColoring(int **graph, int numVertices, int numColors, int *colorArr) {
    if (graphColoringUtil(graph, numVertices, numColors, colorArr, 0) == 0) {
        return 0;
    }
    return 1;
}