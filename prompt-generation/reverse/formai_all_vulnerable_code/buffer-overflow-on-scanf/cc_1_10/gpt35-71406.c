//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

int n, m;
bool graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];

bool isSafe(int node, int color)
{
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && colors[i] == color)
            return false;
    }
    return true;
}

bool graphColoring(int node)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, i)) {
            colors[node] = i;
            if (graphColoring(node+1))
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

void printColors()
{
    for (int i = 0; i < n; i++)
        printf("%d, ", colors[i]);
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            graph[i][j] = x;
        }
    }

    if (graphColoring(0))
        printColors();
    else
        printf("No solution found\n");

    return 0;
}