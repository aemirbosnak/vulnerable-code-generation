//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>

#define MAX_VERTICES 20
#define MAX_COLORS 4

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int vertexCount;
int colorCount;

void setColor(int vertex, int color) {
    colors[vertex] = color;
}

int isColorValid(int vertex, int color) {
    for (int i = 0; i < vertexCount; ++i) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int colorGraph(int vertex) {
    if (vertexCount == vertex) {
        return 1;
    }

    for (int color = 1; color <= colorCount; ++color) {
        if (isColorValid(vertex, color)) {
            setColor(vertex, color);

            if (colorGraph(vertex + 1)) {
                return 1;
            } else {
                setColor(vertex, 0);
            }
        }
    }

    return 0;
}

int main() {
    int edgeCount, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter the number of edges: ");
    scanf("%d", &edgeCount);

    for (int i = 0; i < edgeCount; ++i) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &start, &end);

        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    printf("Enter the number of colors (max %d): ", MAX_COLORS);
    scanf("%d", &colorCount);

    if (colorGraph(0)) {
        printf("Colors assigned as:\n");

        for (int i = 0; i < vertexCount; ++i) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.", colorCount);
    }

    return 0;
}