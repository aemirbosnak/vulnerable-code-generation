//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

int nVertices, nEdges;
int graph[MAX_VERTICES][MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

void makeSet(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

int findSet(int v)
{
    if (parent[v]!= v)
    {
        parent[v] = findSet(parent[v]);
    }
    return parent[v];
}

void unionSet(int u, int v)
{
    int pu = findSet(u);
    int pv = findSet(v);

    if (pu!= pv)
    {
        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            if (rank[pu] == rank[pv])
            {
                rank[pv]++;
            }
        }
    }
}

void kruskalsAlgorithm()
{
    int i, j, u, v, w;

    for (i = 0; i < nVertices; i++)
    {
        makeSet(i);
    }

    for (i = 0; i < nEdges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        unionSet(u, v);
    }

    for (i = 0; i < nVertices; i++)
    {
        for (j = 0; j < nVertices; j++)
        {
            if (graph[i][j] && findSet(i)!= findSet(j))
            {
                printf("%d - %d : %d\n", i, j, graph[i][j]);
            }
        }
    }
}

int main()
{
    int i, j, u, v, w;

    scanf("%d %d", &nVertices, &nEdges);

    for (i = 0; i < nVertices; i++)
    {
        for (j = 0; j < nVertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < nEdges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    kruskalsAlgorithm();

    return 0;
}