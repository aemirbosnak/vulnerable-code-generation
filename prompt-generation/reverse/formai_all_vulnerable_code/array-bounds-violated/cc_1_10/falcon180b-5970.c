//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: artistic
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define V 9
#define INF INT_MAX

int dist[V][V];
int parent[V][V];
int n,m;

void dijkstra(int src,int dest)
{
    int i,j,u,v;
    int min_dist=INF,min_node;
    for(i=0;i<n;i++)
    {
        dist[src][i]=0;
        parent[src][i]=-1;
    }
    dist[src][src]=0;
    for(i=1;i<n;i++)
    {
        min_dist=INF;
        min_node=-1;
        for(j=0;j<n;j++)
        {
            if(dist[src][j]+dist[j][dest]<min_dist)
            {
                min_dist=dist[src][j]+dist[j][dest];
                min_node=j;
            }
        }
        for(u=0;u<n;u++)
        {
            if(dist[src][u]+dist[u][min_node]==min_dist)
            {
                parent[src][min_node]=u;
            }
        }
    }
    printf("\nShortest Path: ");
    int k=dest;
    while(k!=-1)
    {
        printf("%d ",k);
        k=parent[k][dest];
    }
    printf("\nDistance: %d",dist[src][dest]);
}

void input_graph()
{
    int i,j,w;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the number of edges: ");
    scanf("%d",&m);
    printf("\nEnter the edges and their weights:\n");
    for(i=0;i<m;i++)
    {
        printf("\nEnter the vertices and weight of edge %d: ",i+1);
        scanf("%d %d",&j,&w);
        dist[j][i]=w;
        dist[i][j]=w;
    }
}

int main()
{
    printf("\n\n\t\tA* Pathfinding Algorithm\n");
    printf("\nEnter the source and destination nodes: ");
    int src,dest;
    scanf("%d %d",&src,&dest);
    input_graph();
    dijkstra(src,dest);
    return 0;
}