//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include<stdio.h>
#define MAX 10

void graph_coloring(int n,int c[][MAX],int m,int color[])
{
    int i,j,u,flag[MAX],count=0;
    for(i=0;i<n;i++)
    {
        color[i]=0;
        flag[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(c[i][j]==1)
            {
                flag[color[j]]=1;
            }
        }
        u=0;
        while(flag[u]==1)
        {
            u++;
        }
        color[i]=u;
        for(j=0;j<n;j++)
        {
            flag[j]=0;
        }
        if(color[i]>count)
        {
            count=color[i];
        }
    }
    if(count>m)
    {
        printf("The graph is not %d-colorable\n",m);
    }
    else
    {
        printf("The graph is %d-colorable\n",m);
    }
}

void main()
{
    int i,j,n,m,c[MAX][MAX],color[MAX];
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d",&m);
    graph_coloring(n,c,m,color);
    printf("The colors of the vertices are:\n");
    for(i=0;i<n;i++)
    {
        printf("Vertex %d - Color %d\n",i+1,color[i]+1);
    }
}