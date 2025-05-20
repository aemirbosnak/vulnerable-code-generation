//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int graph[MAX][MAX];
int nvertices;
int ncolors;
int colors[MAX];

void init_graph(int vertices) {
    nvertices = vertices;
    memset(graph, 0, sizeof(graph));
    memset(colors, 0, sizeof(colors));
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
}

int backtrack(int vertex, int color) {
    if (vertex == nvertices) {
        return 1;
    }

    for (int i = 1; i <= ncolors; i++) {
        if ((graph[vertex][colors[vertex]] & (1 << i)) == 0) {
            colors[vertex] = i;
            if (backtrack(vertex + 1, color)) {
                return 1;
            }
        }
    }

    return 0;
}

int color(int color) {
    memset(colors, 0, sizeof(colors));
    colors[0] = color;

    int result = backtrack(1, color);

    if (result) {
        printf("Vertex\tColor\n");
        for (int i = 0; i < nvertices; i++) {
            printf("%d\t%d\n", i, colors[i]);
        }
    }

    return result;
}

int main() {
    int vertices, edges;

    scanf("%d%d", &vertices, &edges);

    init_graph(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }

    int result = color(1);

    if (result == 0) {
        printf("No solution exists.\n");
    }

    return 0;
}