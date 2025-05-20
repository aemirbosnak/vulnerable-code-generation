//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500

int graph[MAX_VERTICES][MAX_VERTICES];
int vertices, edges;

void generateGraph() {
    int i, j, v1, v2;
    for (i = 0; i < edges; i++) {
        v1 = rand() % vertices;
        v2 = rand() % vertices;
        if (v1 == v2)
            i--;
        else if (graph[v1][v2] != 0)
            i--;
        else {
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
        }
    }
}

int colorGraph(int colors[MAX_VERTICES]) {
    int i, j, k, color, colored = 0;

    for (i = 0; i < vertices; i++) {
        color = 0;
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] != 0 && colors[j] == color) {
                color++;
                j = -1;
            }
        }
        colors[i] = color;
        if (color != 0)
            colored++;
    }

    return colored;
}

int main() {
    printf("Enter number of vertices (0 < vertices <= %d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    printf("Enter number of edges (0 < edges <= %d): ", MAX_EDGES);
    scanf("%d", &edges);

    if (edges > vertices * (vertices - 1) / 2) {
        printf("Too many edges!\n");
        return 1;
    }

    generateGraph();

    int colors[MAX_VERTICES];
    int colored = colorGraph(colors);

    printf("Graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of Colored Vertices: %d\n", colored);
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d is colored with %d\n", i+1, colors[i]+1);
    }

    return 0;
}