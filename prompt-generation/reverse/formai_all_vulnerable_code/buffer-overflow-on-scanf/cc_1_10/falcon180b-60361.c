//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 9

int graph[V][V];

void addedge(int v, int w);
void printgraph(int graph[V][V]);

int main() {
    int i, j, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges with vertices and weight:\n");

    while (true) {
        scanf("%d%d", &v, &w);

        if (v == -1 && w == -1) {
            break;
        }

        addedge(v, w);
    }

    printgraph(graph);

    return 0;
}

void addedge(int v, int w) {
    graph[v][w] = graph[w][v] = 1;
}

void printgraph(int graph[V][V]) {
    int i, j;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                printf("%d -- %d (%d)\n", i, j, graph[i][j]);
            }
        }
    }
}