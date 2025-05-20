//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODE 10
#define MAX_COLOR 4

int adjMatrix[MAX_NODE][MAX_NODE];
int color[MAX_NODE];

bool isSafe(int node, int c, int n) {
    for(int i = 0; i < n; i++) {
        if(adjMatrix[node][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoring(int node, int n, int m) {
    if(node == n)
        return true;

    for(int i = 1; i <= m; i++) {
        if(isSafe(node, i, n)) {
            color[node] = i;
            if(graphColoring(node + 1, n, m))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

void printColoring(int n) {
    printf("Coloring of Graph: \n");
    for(int i = 0; i < n; i++)
        printf("Node %d has Color %d\n", i, color[i]);
}

int main() {
    int n, m, e, x, y;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter maximum number of colors: ");
    scanf("%d", &m);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(int i = 0; i < e; i++) {
        printf("Enter edge u, v: ");
        scanf("%d %d", &x, &y);
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    if(graphColoring(0, n, m))
        printColoring(n);
    else
        printf("Graph cannot be colored with %d colors", m);

    return 0;
}