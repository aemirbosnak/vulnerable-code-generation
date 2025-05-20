//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int n;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

bool isSafe(int vert, int c) {
    for(int i = 0; i < n; i++)
        if(graph[vert][i] && c == color[i])
            return false;
    return true;
}

bool graphColorUtil(int vert, int numColors) {
    if(vert == n)
        return true;

    for(int c = 1; c <= numColors; c++) {
        if(isSafe(vert, c)) {
            color[vert] = c;
            if(graphColorUtil(vert+1, numColors))
                return true;
            color[vert] = 0;
        }
    }

    return false;
}

bool graphColoring(int numColors) {
    memset(color, 0, sizeof color);
    return graphColorUtil(0, numColors);
}

int main() {
    int m, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter the maximum number of colors: ");
    scanf("%d", &m);

    if(graphColoring(m)) {
        printf("Graph is colorable using at most %d colors.\nThe color assignment is:\n", m);
        for(int i = 0; i < n; i++)
            printf("%d ", color[i]);
    }
    else
        printf("Graph is not colorable using %d colors.", m);

    return 0;
}