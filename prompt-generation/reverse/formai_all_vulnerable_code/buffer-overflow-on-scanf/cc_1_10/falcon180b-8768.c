//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int graph[MAXN][MAXN];
int n, m;
int color[MAXN];

void init()
{
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            graph[i][j] = 0;
}

void add_edge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void dfs(int u)
{
    color[u] = 1;
    for (int v = 0; v < n; ++v)
        if (graph[u][v])
        {
            int k = 1;
            while (color[v] == k || color[v] == -k)
                ++k;
            color[v] = -k;
            dfs(v);
        }
}

int main()
{
    int i, j, k, u, v;
    char s[10];
    scanf("%d %d", &n, &m);
    init();
    for (i = 0; i < m; ++i)
    {
        scanf("%s", s);
        k = s[0] - 'A';
        u = s[2] - 'A';
        v = s[4] - 'A';
        add_edge(k, u);
        add_edge(k, v);
    }
    for (i = 0; i < n; ++i)
        if (color[i] == 0)
        {
            dfs(i);
            ++color[i];
        }
    printf("Minimum number of colors = %d\n", color[0]);
    return 0;
}