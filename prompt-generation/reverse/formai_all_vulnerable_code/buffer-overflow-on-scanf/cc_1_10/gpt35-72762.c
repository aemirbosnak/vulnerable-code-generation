//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int vertices;
int colors[MAX_VERTICES] = {0};

void colorVertex(int vertex) {
    int i, used_colors[MAX_VERTICES] = {0};

    for (i = 0; i < vertices; ++i)
        if (graph[vertex][i] && colors[i])
            used_colors[colors[i]] = 1;

    for (i = 1; i <= vertices; ++i)
        if (!used_colors[i]) {
            colors[vertex] = i;
            return;
        }
}

int assignColors() {
    int i;

    for (i = 0; i < vertices; ++i)
        colorVertex(i);

    return 1;
}

int main() {
    int i, j;

    printf("Surprise! We will now solve the Graph Coloring Problem.\n");

    printf("Please enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    printf("Please enter the adjacency matrix of the graph (1 if there is an edge, 0 otherwise):\n");
    for (i = 0; i < vertices; ++i)
        for (j = 0; j < vertices; ++j)
            scanf("%d", &graph[i][j]);

    if (assignColors()) {
        printf("\nCongratulations! We were able to successfully color the graph.\n");
        printf("The colors assigned to the vertices are:\n");
        for (i = 0; i < vertices; ++i)
            printf("Vertex %d: Color %d\n", i+1, colors[i]);
    } else {
        printf("\nOops! We were unable to color the graph. Please try again with a different adjacency matrix.\n");
    }

    return 0;
}