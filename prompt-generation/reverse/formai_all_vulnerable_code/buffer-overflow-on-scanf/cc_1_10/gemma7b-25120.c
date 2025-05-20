//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
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
            color[i] = color[current] ^ 1;
            dfs(i);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    dfs(0);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }

    printf("\n");

    return 0;
}