//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>

#define MAX_VERTICES 10
#define MAX_EDGES 15

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int colors[MAX_VERTICES] = {0};
    int num_vertices, num_edges;

    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edge pairs (vertex indices): \n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int num_colors = 0;
    for (int vertex = 0; vertex < num_vertices; vertex++) {
        int available_colors[MAX_VERTICES] = {0};

        for (int i = 0; i < num_vertices; i++) {
            if (graph[vertex][i] && colors[i]) {
                available_colors[colors[i]] = 1;
            }
        }

        int color;
        for (color = 1; color <= num_colors; color++) {
            if (!available_colors[color]) {
                break;
            }
        }

        if (color > num_colors) {
            num_colors++;
        }

        colors[vertex] = color;
    }

    printf("Colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: %d\n", i, colors[i]);
    }

    printf("Number of colors used: %d\n", num_colors);

    return 0;
}