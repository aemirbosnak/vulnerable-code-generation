//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define V 9

#define INF 999999

int graph[V][V];
int color[V];

void printSolution(int n)
{
    printf("\nVertex   Color\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, color[i]);
    }
}

int isSafe(int v, int c, int color[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

void backtrack(int v, int n)
{
    int i;
    for (i = 1; i <= n; i++) {
        if (isSafe(v, i, color, n)) {
            color[v] = i;
            if (v == n - 1) {
                printSolution(n);
                exit(0);
            }
            backtrack(v + 1, n);
        }
    }
}

int main()
{
    int i, j;
    printf("Enter 0 or 1 for edges\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int n = 0;
    for (i = 0; i < V; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            if (i == V - 1) {
                printSolution(n);
                exit(0);
            }
            backtrack(i + 1, n + 1);
        }
    }

    return 0;
}