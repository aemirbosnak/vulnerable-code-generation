//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 6

/*Graph Coloring Problem*/

int G[N][N] = {
                {0, 1, 0, 1, 0, 0},
                {1, 0, 1, 0, 1, 0},
                {0, 1, 0, 0, 0, 1},
                {1, 0, 0, 0, 1, 0},
                {0, 1, 0, 1, 0, 1},
                {0, 0, 1, 0, 1, 0}
            };

int m; //number of colors

void printSolution(int color[])
{
    printf("Colors assigned to vertices are : \n");
    for(int i=0;i<N;i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

int isSafe(int v, int color[], int c)
{
    for(int i=0;i<N;i++)
    {
        if(G[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoringUtil(int color[], int v)
{
    if(v == N)
        return 1;
    for(int c=1;c<=m;c++)
    {
        if(isSafe(v, color, c))
        {
            color[v] = c;
            if(graphColoringUtil(color, v+1) == 1)
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

void graphColoring()
{
    int color[N];
    for(int i=0;i<N;i++)
        color[i] = 0;
    if(graphColoringUtil(color, 0) == 0)
        printf("Solution does not exist");
    else
        printSolution(color);
}

int main()
{
    printf("Surprise! We are coloring the graph\n");
    printf("Enter number of colors: ");
    scanf("%d",&m);
    graphColoring();
    return 0;
}