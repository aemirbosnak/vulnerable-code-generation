//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int G[MAX][MAX], degrees[MAX], color[MAX], n, m;

void read_graph()
{
    int i, j, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter %d edges(u v):\n", m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
}

int get_degree(int u)
{
    int i, degree = 0;
    for(i = 0; i < n; i++)
    {
        if(G[u][i])
        {
            degree++;
        }
    }
    return degree;
}

void print_graph()
{
    int i, j;
    printf("Adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void print_color(int *color)
{
    int i;
    printf("\nColors:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int get_available_color(int u)
{
    int i, j, v;
    int available[MAX];
    int k = 0;
    for(i = 0; i < n; i++)
    {
        available[i] = 1;
    }
    for(i = 0; i < n; i++)
    {
        if(G[u][i] && color[i] != -1)
        {
            available[color[i]] = 0;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(available[i])
        {
            return i;
        }
    }
    return -1;
}

void graph_coloring()
{
    int i, j, u;
    for(i = 0; i < n; i++)
    {
        color[i] = -1;
        degrees[i] = get_degree(i);
    }
    for(i = 0; i < n; i++)
    {
        u = i;
        for(j = 0; j < n; j++)
        {
            if(degrees[j] > degrees[u])
            {
                u = j;
            }
        }
        color[u] = get_available_color(u);
        degrees[u] = -1;
        for(j = 0; j < n; j++)
        {
            if(G[u][j] && degrees[j] != -1)
            {
                degrees[j]--;
            }
        }
    }
}

int main()
{
    read_graph();
    print_graph();
    graph_coloring();
    print_color(color);
    return 0;
}