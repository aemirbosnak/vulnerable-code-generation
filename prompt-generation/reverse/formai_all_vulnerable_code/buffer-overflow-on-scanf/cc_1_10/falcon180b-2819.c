//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_GRAPH_NODES 100
#define MAX_GRAPH_EDGES 200

int graph[MAX_GRAPH_NODES][MAX_GRAPH_EDGES];
int nVertices, nEdges;
int color[MAX_GRAPH_NODES];

void initGraph(int v, int e)
{
    nVertices = v;
    nEdges = e;
    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v)
{
    graph[u][v] = 1;
}

void printGraph()
{
    for(int i=0; i<nVertices; i++)
    {
        for(int j=0; j<nVertices; j++)
        {
            if(graph[i][j] == 1)
            {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

int isSafe(int v, int c, int color[])
{
    for(int i=0; i<nVertices; i++)
    {
        if(graph[v][i] == 1 && color[i] == c)
        {
            return 0;
        }
    }
    return 1;
}

void colorGraph(int startV)
{
    int c = 1;
    color[startV] = c;
    for(int i=0; i<nVertices; i++)
    {
        if(color[i] == 0)
        {
            if(isSafe(i, c, color))
            {
                color[i] = c;
            }
            else
            {
                c++;
                color[i] = c;
            }
        }
    }
}

int main()
{
    int v, e;
    printf("Enter the number of vertices and edges in the graph:\n");
    scanf("%d %d", &v, &e);

    initGraph(v, e);
    printf("Enter the edges of the graph:\n");
    for(int i=0; i<e; i++)
    {
        int u, w;
        printf("Enter the vertices of edge %d:\n", i+1);
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    colorGraph(0);

    printf("\nThe colored graph is:\n");
    printGraph();

    return 0;
}