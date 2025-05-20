//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 5

int graph[MAX_VERTICES][MAX_VERTICES];
int vertices, edges;
int colors[MAX_VERTICES];

bool is_safe(int vertex, int color) {
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool color_graph(int vertex) {
    if (vertex == vertices) {
        printf("The graph can be colored with the following colors:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
        return true;
    }

    for (int i = 1; i <= MAX_COLORS; i++) {
        if (is_safe(vertex, i)) {
            colors[vertex] = i;

            if (color_graph(vertex + 1)) {
                return true;
            }

            colors[vertex] = 0;
        }
    }

    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edge pairs (Eg: 1 2): \n");
    for (int i = 0; i < edges; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }

    bool has_solution = color_graph(0);

    if (!has_solution) {
        printf("The graph cannot be colored with %d or fewer colors.\n", MAX_COLORS);
    }

    return 0;
}