//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];
int color[MAX];
int visited[MAX];

void dfs(int current)
{
    visited[current] = 1;
    for(int i = 0; i < MAX; i++)
    {
        if(graph[current][i] && !visited[i])
        {
            color[i] = color[current];
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter number of nodes: ", &n);
    scanf("Enter number of edges: ", &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter edge between nodes: ", &u);
        scanf("Enter edge between nodes: ", &v);
        graph[u][v] = 1;
    }

    dfs(0);

    for(int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, color[i]);
    }

    return 0;
}