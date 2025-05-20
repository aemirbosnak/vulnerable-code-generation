//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int n;

void initGraph() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

}

int isSafe(int vertex, int color) {
    int i;

    for(i = 0; i < n; i++){
        if (graph[vertex][i] && color == colors[i])
            return 0;
    }

    return 1;
}

void printColors() {
    int i;

    printf("Vertex colors:\n");
    for(i = 0; i < n; i++)
        printf("%d -> %d\n", i+1, colors[i]);
}

int graphColoring(int vertex) {
    int color;

    if(vertex == n)
        return 1;

    for(color = 1; color <= n; color++) {

        if(isSafe(vertex, color)) {

            colors[vertex] = color;

            if(graphColoring(vertex+1))
                return 1;

            colors[vertex] = 0;

        }
    }
    return 0;
}

int main() {

    int result;

    initGraph();

    result = graphColoring(0);

    if(result)
        printColors();
    else
        printf("Graph cannot be colored!");

    return 0;
}