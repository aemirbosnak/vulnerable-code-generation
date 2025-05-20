//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 6

typedef struct {
    int color;
    int vertex;
} Vertex;

void initialize_graph(Vertex *graph, int n) {
    for (int i = 0; i < n; i++) {
        graph[i].color = INT_MAX;
        graph[i].vertex = INT_MAX;
    }
}

int get_color(Vertex *graph, int n, int vertex) {
    int color = graph[vertex].color;
    if (color!= INT_MAX)
        return color;

    for (int i = 0; i < n; i++) {
        if (graph[i].vertex == vertex)
            return graph[i].color;

        color = get_color(graph, n, graph[i].vertex);
        if (color!= INT_MAX)
            return color;
    }

    return INT_MAX;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    Vertex *graph = (Vertex *)malloc(n * sizeof(Vertex));
    initialize_graph(graph, n);

    printf("Enter the edges: ");
    int vertex1, vertex2;
    while (scanf("%d %d", &vertex1, &vertex2)!= EOF) {
        graph[vertex1].color = get_color(graph, n, vertex2);
        graph[vertex2].color = get_color(graph, n, vertex1);
    }

    printf("The graph is %d-colorable.\n", get_color(graph, n, 0));

    free(graph);
    return 0;
}