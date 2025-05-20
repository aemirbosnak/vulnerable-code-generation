//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: light-weight
#include<stdio.h>
#include<limits.h>
#define V 9
#define INF INT_MAX
int dist[V][V];
int parent[V][V];
int n,m;
void dijkstra(int src,int dest)
{
    int u,v,i,j,k;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            dist[i][j]=INF;
            parent[i][j]=-1;
        }
    }
    dist[src][src]=0;
    for(k=0;k<V-1;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    parent[i][j]=k;
                }
            }
        }
    }
    printf("Vertex\t Distance from Source\n");
    for(i=0;i<V;i++)
    {
        printf("%d \t %d\n",i,dist[src][i]);
    }
    printf("\nPath: ");
    if(parent[dest][src]!=-1)
    {
        i=dest;
        while(parent[i][src]!=-1)
        {
            printf("%d ",i);
            i=parent[i][src];
        }
        printf("%d ",src);
    }
    else
    {
        printf("No Path Exists");
    }
}
int main()
{
    int graph[V][V]={{0,4,0},{4,0,8},{0,8,2},{8,2,1},{1,2,0},{2,1,4},{2,5,3},{5,7,6},{6,3,7}};
    int src,dest;
    printf("Enter the Source and Destination Nodes:\n");
    scanf("%d %d",&src,&dest);
    dijkstra(src,dest);
    return 0;
}