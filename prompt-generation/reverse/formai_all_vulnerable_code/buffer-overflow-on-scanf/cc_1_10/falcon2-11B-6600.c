//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_NODES 100
#define MAX_EDGES 100

int color[MAX_NODES];
int parent[MAX_NODES];

int find(int x)
{
    if (color[x] == x)
        return x;
    return color[x] = find(color[x]);
}

void union_set(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if (color[px] < color[py])
        parent[px] = py;
    else
        parent[py] = px;

    if (color[px] == color[py])
    {
        color[py] = color[px] + 1;
    }
}

void Graph_Coloring(int V, int E)
{
    int i, j, k;
    for (i = 0; i < V; i++)
    {
        color[i] = i;
        parent[i] = i;
    }

    for (i = 0; i < E; i++)
    {
        int u = (rand() % V) + 1;
        int v = (rand() % V) + 1;

        if (color[u] == color[v])
        {
            union_set(u, v);
        }
    }
}

void Print_Colors(int V)
{
    int i;
    printf("Colors assigned to the vertices are : \n");
    for (i = 1; i <= V; i++)
    {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main()
{
    int V, E;
    printf("Enter the number of vertices : ");
    scanf("%d", &V);

    printf("Enter the number of edges : ");
    scanf("%d", &E);

    Graph_Coloring(V, E);

    Print_Colors(V);

    return 0;
}