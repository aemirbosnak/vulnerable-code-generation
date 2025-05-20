//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void print_graph(int **graph, int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int min_color(int **graph, int vertices, int *color, int current_color) {
    for (int i = 0; i < vertices; i++) {
        if (graph[current_color][i] == 1 && color[i] == -1) {
            color[i] = current_color;
            int next_color = min_color(graph, vertices, color, (current_color + 1) % vertices);
            if (next_color == -1)
                return current_color;
        }
    }
    return -1;
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int **graph = (int **)calloc(vertices, sizeof(int *));
    for (int i = 0; i < vertices; i++)
        graph[i] = (int *)calloc(vertices, sizeof(int));

    printf("Enter edges (u, v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    print_graph(graph, vertices);

    int *color = (int *)calloc(vertices, sizeof(int));
    for (int i = 0; i < vertices; i++)
        color[i] = -1;

    int first_color = min_color(graph, vertices, color, 0);

    printf("\nMinimum number of colors required: %d\n", first_color + 1);

    free(graph);
    for (int i = 0; i < vertices; i++)
        free(graph[i]);
    free(graph);
    free(color);

    return 0;
}