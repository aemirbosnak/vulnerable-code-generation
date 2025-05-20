//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100
#define MAX_E 200
#define INF 999999

int V, E;
int adj_matrix[MAX_V][MAX_V];
int color[MAX_V];
int min_color;

void init()
{
    srand(time(NULL));
    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++)
            adj_matrix[i][j] = 0;
}

void add_edge(int u, int v)
{
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

int is_safe(int v, int c)
{
    for (int i = 0; i < V; i++)
        if (adj_matrix[v][i] && color[i] == c)
            return 0;
    return 1;
}

void backtrack(int v, int c)
{
    color[v] = c;
    for (int i = 0; i < V; i++)
        if (adj_matrix[v][i] &&!color[i])
            backtrack(i, c);
}

int main()
{
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    init();

    for (int i = 0; i < E; i++)
    {
        int u, v;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    int max_color = 1;
    for (int i = 0; i < V; i++)
    {
        if (!color[i])
        {
            min_color = max_color;
            backtrack(i, max_color++);
        }
    }

    printf("Minimum number of colors required: %d\n", min_color);

    return 0;
}