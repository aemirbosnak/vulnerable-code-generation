//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: shocked
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

#define V 9

int dist[V][V];
int parent[V][V];
int visited[V][V];

void dijkstra(int graph[V][V],int src,int dest)
{
    int u,v,i,j,min,k;

    for(i=0;i<V;i++)
    {
        dist[src][i]=INT_MAX;
        parent[src][i]=-1;
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

    printf("\nVertex\t Distance from Source\n");

    for(i=0;i<V;i++)
    {
        printf("%d \t %d\n",i,dist[src][i]);
    }

    printf("\nPath: ");
    k=dest;

    while(k!=-1)
    {
        printf("%d ",k);
        k=parent[k][dest];
    }
}

int main()
{
    int graph[V][V]={{0,4,0,0,0,0,0,8,0},
                    {4,0,8,0,0,0,0,11,0},
                    {0,8,0,7,0,4,0,0,2},
                    {0,0,7,0,9,14,0,0,0},
                    {0,0,0,9,0,10,0,1,0},
                    {0,0,4,14,10,0,2,0,4},
                    {0,0,0,0,0,2,1,0,1},
                    {8,11,0,0,1,0,0,7,8},
                    {0,0,2,0,4,1,8,6,0}};

    int source,dest;

    printf("Enter the source vertex: ");
    scanf("%d",&source);

    printf("Enter the destination vertex: ");
    scanf("%d",&dest);

    dijkstra(graph,source,dest);

    return 0;
}