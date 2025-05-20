//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXV 100 

int colors[MAXV];
bool adjMatrix[MAXV][MAXV];

void initializeGraph() {
    int i, j;
    for (i = 0; i < MAXV; i++) {
        for (j = 0; j < MAXV; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

void addEdge(int u, int v) {
    adjMatrix[u][v] = true;
    adjMatrix[v][u] = true;
}

bool isSafe(int v, int color, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (adjMatrix[v][i] && color == colors[i])
            return false;
    }
    return true;
}

bool graphColor(int v, int n, int m) {
    int i;
    if (v == n)
        return true;

    for (i = 1; i <= m; i++) {
        if (isSafe(v, i, n)) {
            colors[v] = i;

            if (graphColor(v + 1, n, m))
                return true;
            colors[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m, u, v, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    initializeGraph();

    printf("\nEnter the number of edges: ");
    scanf("%d", &m);

    printf("\nEnter the edges (u,v): \n");
    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }

    printf("\nEnter the number of colors: ");
    scanf("%d", &m);

    if (graphColor(0, n, m)) {
        printf("\nGraph is %d-colorable\n", m);
        printf("Color assigned to vertices are:\n");
        for (i = 0; i < n; i++)
            printf("Vertex %d: Color %d\n", i, colors[i]);
    } else {
        printf("\nGraph is not %d-colorable\n", m);
    }
    return 0;
}