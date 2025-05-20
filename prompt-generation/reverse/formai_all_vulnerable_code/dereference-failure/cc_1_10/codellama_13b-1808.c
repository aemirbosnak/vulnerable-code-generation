//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: imaginative
/*
 * Unique C Graph Representation Example Program
 *
 * This program demonstrates a graph representation using a matrix, where each
 * vertex is represented by a row and each edge is represented by a non-zero
 * entry in the corresponding row and column.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int vertex1;
    int vertex2;
    int weight;
} Edge;

void add_edge(int **graph, int v1, int v2, int wt) {
    graph[v1][v2] = wt;
    graph[v2][v1] = wt;
}

void remove_edge(int **graph, int v1, int v2) {
    graph[v1][v2] = 0;
    graph[v2][v1] = 0;
}

int main() {
    int **graph = (int **)malloc(MAX_VERTICES * sizeof(int *));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = (int *)malloc(MAX_VERTICES * sizeof(int));
    }

    add_edge(graph, 1, 2, 10);
    add_edge(graph, 2, 3, 20);
    add_edge(graph, 1, 3, 30);
    add_edge(graph, 3, 4, 40);
    add_edge(graph, 4, 5, 50);

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (graph[i][j] != 0) {
                printf("(%d, %d) %d\n", i, j, graph[i][j]);
            }
        }
    }

    remove_edge(graph, 1, 2);

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (graph[i][j] != 0) {
                printf("(%d, %d) %d\n", i, j, graph[i][j]);
            }
        }
    }

    for (int i = 0; i < MAX_VERTICES; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}