//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include<stdio.h>
int graph[1000][1000];
int color[1000];
int n,m;

void colorGraphUtil(int v)
{
    int i,j,avail[1000];
    for(i=1;i<=m;i++)
    {
        avail[i]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(graph[v][i] && color[i]!=-1)
        {
            avail[color[i]]=0;
        }
    }
    for(i=1;i<=m;i++)
    {
        if(avail[i])
        {
            color[v]=i;
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(graph[v][i] && color[i]==-1)
        {
            colorGraphUtil(i);
        }
    }
}

void colorGraph()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        color[i]=-1;
    }
    for(i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            colorGraphUtil(i);
        }
    }
    printf("\nThe minimum number of colors required to color the graph is %d\n",m);
    printf("\nThe following are the colors assigned to the corresponding graph vertices\n\n");
    for(i=1;i<=n;i++)
    {
        printf("Vertex %d -> Color %d\n",i,color[i]);
    }
}

int main()
{
    int i,j,u,v;
    printf("Enter the number of vertices in the graph\n");
    scanf("%d",&n);
    printf("Enter the number of colors to be used for coloring the graph\n");
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            graph[i][j]=0;
        }
    }
    printf("\nEnter the number of edges\n");
    int e;
    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
        printf("\nEnter edge %d\n",i);
        scanf("%d%d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    colorGraph();
    return 0;
}