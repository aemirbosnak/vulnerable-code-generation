//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int adj[MAX][MAX];
int color[MAX];
int n, m;

bool isSafe(int v, int c)
{
    for(int i=0; i<n; i++)
    {
        if(adj[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoring(int v)
{
    if(v == n)
        return true;

    for(int i=1; i<=m; i++)
    {
        if(isSafe(v, i))
        {
            color[v] = i;
            if(graphColoring(v+1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    int e;
    scanf("%d", &e);
    printf("Enter the vertices for each edge: ");
    for(int i=0; i<e; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }

    printf("\nResult:\n");

    if(graphColoring(0))
    {
        for(int i=0; i<n; i++)
            printf("Vertex %d is colored with color %d\n", i+1, color[i]);
    }
    else
    {
        printf("Solution does not exist!\n");
    }

    return 0;
}