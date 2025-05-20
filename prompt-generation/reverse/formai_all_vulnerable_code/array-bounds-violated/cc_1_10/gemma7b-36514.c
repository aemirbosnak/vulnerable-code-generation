//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int color[MAX];
int visited[MAX];

void dfs(int node)
{
    visited[node] = 1;
    for (int i = 0; i < MAX; i++)
    {
        if (graph[node][i] && !visited[i] && color[node] != color[i])
        {
            color[i] = color[node];
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes: ", &n);
    scanf("Enter the number of edges: ", &m);

    for (int i = 0; i < n; i++)
    {
        graph[i][0] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the two nodes: ", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    dfs(0);

    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, color[i]);
    }

    return 0;
}