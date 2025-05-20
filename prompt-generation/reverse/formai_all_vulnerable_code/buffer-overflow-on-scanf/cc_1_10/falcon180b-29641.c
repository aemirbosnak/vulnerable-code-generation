//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 10
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int n;
int m;

void dfs(int v, int color)
{
    colors[v] = color;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && colors[i] == WHITE) {
            dfs(i, color + 1);
        }
    }
}

int main()
{
    int i, j, k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &j, &k);
        graph[j][k] = 1;
        graph[k][j] = 1;
    }

    for (i = 0; i < n; i++) {
        if (colors[i] == WHITE) {
            dfs(i, 0);
        }
    }

    printf("Vertex\tColor\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }

    return 0;
}