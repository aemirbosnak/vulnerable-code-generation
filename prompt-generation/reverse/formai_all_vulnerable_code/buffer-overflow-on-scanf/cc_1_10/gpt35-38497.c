//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int graph[MAX][MAX];
int colors[MAX];

bool isSafe(int v, int c, int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i] && c==colors[i]) return false;
    }
    return true;
}

bool graphColoringUtil(int v, int n, int m)
{
    if(v==n) return true;

    for(int c=1;c<=m;c++)
    {
        if(isSafe(v,c,n))
        {
            colors[v]=c;
            if(graphColoringUtil(v+1,n,m)) return true;
            colors[v]=0;
        }
    }
    return false;
}

bool graphColoring(int n, int m)
{
    if(!graphColoringUtil(0,n,m))
    {
        printf("Coloring not possible with %d colors.\n",m);
        return false;
    }
    printf("Coloring is possible with %d colors:\n",m);
    for(int i=0;i<n;i++)
    {
        printf("Vertex %d: Color %d\n",i+1,colors[i]);
    }
    return true;
}

int main()
{
    int n=0,m=0;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix of the graph:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d",&m);

    if(graphColoring(n,m)) return 0;
    else return 1;
}