//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

typedef struct {
    int vertex1;
    int vertex2;
} Edge;

typedef struct {
    int adjMat[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int numEdges;
} Graph;

void printGraph(Graph g) {
    printf("Adjacency Matrix Representation of Graph:\n");
    for (int i = 0; i < g.numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < g.numVertices; j++) {
            printf(" %d", g.adjMat[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(Graph g, int vertex, int color[]) {
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMat[vertex][i] != 0 && color[i] == color[vertex]) {
            return false;
        }
    }
    return true;
}

int graphColoringHelper(Graph g, int m, int color[], int vertex) {
    if (vertex >= g.numVertices) {
        return 1; // All vertices have been colored
    }

    for (int i = 1; i <= m; i++) {
        color[vertex] = i;
        if (isSafe(g, vertex, color)) {
            if (graphColoringHelper(g, m, color, vertex + 1) == 1) {
                return 1;
            }
        }
        color[vertex] = 0; // Backtrack
    }

    return 0;
}

int graphColoring(Graph g, int m) {
    int color[MAX_VERTICES] = {0};
    if (graphColoringHelper(g, m, color, 0) == 1) {
        printGraph(g);
        printf("\nSuccessfully Colored the Graph with %d Colors!\n", m);
        for (int i = 0; i < g.numVertices; i++) {
            printf("Vertex %d is colored with Color %d\n", i, color[i]);
        }
    } else {
        printf("\nGraph is not colorable with %d colors.\n", m);
    }
}

int main() {
    int edges, vertices;
    scanf("%d %d", &vertices, &edges);

    Graph g = {.numVertices = vertices, .numEdges = edges};

    srand(time(NULL));

    for (int i = 0; i < edges; i++) {
        Edge e;
        scanf("%d %d", &e.vertex1, &e.vertex2);
        g.adjMat[e.vertex1][e.vertex2] = 1;
        g.adjMat[e.vertex2][e.vertex1] = 1;
    }

    int m;
    scanf("%d", &m);

    graphColoring(g, m);

    return 0;
}