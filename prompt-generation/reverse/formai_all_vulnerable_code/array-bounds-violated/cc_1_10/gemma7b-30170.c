//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int color[MAX];
int visited[MAX];

void dfs(int current)
{
    visited[current] = 1;
    for (int i = 0; i < MAX; i++)
    {
        if (graph[current][i] && !visited[i])
        {
            color[i] = color[current] ^ 1;
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of nodes and edges:", &n, &m);

    // Create the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("Enter the edges:", &u, &v);
        graph[u][v] = 1;
    }

    // Initialize the color and visited arrays
    for (int i = 0; i < n; i++)
    {
        color[i] = 0;
        visited[i] = 0;
    }

    // Perform DFS and color the nodes
    dfs(0);

    // Print the colored nodes
    for (int i = 0; i < n; i++)
    {
        printf("Node %d has color %d\n", i, color[i]);
    }

    return 0;
}