//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_VERTEX 10
#define MAX_COLOR 6
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define FALSE 0
#define TRUE 1

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];
int n;

void init_graph(int v)
{
    int i,j;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            graph[i][j]=0;
        }
    }
}

void init_color()
{
    int i;

    for(i=0;i<n;i++)
    {
        color[i]=WHITE;
    }
}

void print_graph(int v)
{
    int i,j;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(graph[i][j]==1)
            {
                printf(" %d ",graph[i][j]);
            }
            else
            {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

void print_color(int v)
{
    int i;

    for(i=0;i<v;i++)
    {
        printf(" %d ",color[i]);
    }
    printf("\n");
}

void dfs(int v,int c,int parent)
{
    int i;

    color[v]=c;

    for(i=0;i<n;i++)
    {
        if(graph[v][i]==1 && i!=parent && color[i]==WHITE)
        {
            dfs(i,c+1,v);
        }
    }
}

int main()
{
    int i,j;

    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    init_graph(n);

    printf("Enter the adjacency matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    init_color();

    int max_color=0;

    for(i=0;i<n;i++)
    {
        if(color[i]==WHITE)
        {
            dfs(i,0,-1);

            if(color[i]>max_color)
            {
                max_color=color[i];
            }
        }
    }

    printf("The chromatic number of the graph is: %d\n",max_color);

    return 0;
}