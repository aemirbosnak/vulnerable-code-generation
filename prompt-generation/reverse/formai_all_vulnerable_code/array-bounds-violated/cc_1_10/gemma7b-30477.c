//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
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
            color[i] = 3 - color[current];
            dfs(i);
        }
    }
}

int main()
{
    int i, j, n, m;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    printf("Enter the adjacency list:");
    for(i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    dfs(0);

    printf("The coloring is:");
    for(i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }

    return 0;
}