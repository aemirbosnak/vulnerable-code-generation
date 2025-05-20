//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int graph[MAX][MAX];
int color[MAX];
int visited[MAX];

void dfs(int node)
{
    visited[node] = 1;
    for (int i = 0; i < MAX; i++)
    {
        if (graph[node][i] && !visited[i])
        {
            color[i] = color[node] ^ 1;
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    scanf(" %d ", &n);
    scanf(" %d ", &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %d ", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", color[i]);
    }

    return 0;
}