//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define V 9
#define INF INT_MAX

int dist[V][V];
int parent[V][V];

void dijkstra(int src,int dest)
{
    int i,j,u;
    int min_dist=INF,min_index;

    for(i=0;i<V;i++)
    {
        dist[src][i]=0;
        parent[src][i]=-1;
    }

    dist[src][dest]=0;

    for(i=1;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(dist[src][j]>0 && dist[src][j]+dist[src][i]<dist[src][dest])
            {
                dist[src][dest]=dist[src][j]+dist[src][i];
                parent[src][dest]=j;
            }
        }
    }

    printf("\nVertex\t Distance from Source\tPath");

    for(i=0;i<V;i++)
    {
        if(i!=src && i!=dest)
        {
            printf("\n%d\t\t%d\t\t",i,dist[src][i]);
            u=parent[src][i];

            while(u!=-1)
            {
                printf("%d ",u);
                u=parent[src][u];
            }
        }
    }

    printf("\n\nPath from %d to %d: ",src,dest);

    u=dest;

    while(u!=src)
    {
        printf("%d ",u);
        u=parent[src][u];
    }

    printf("%d\n",src);
}

int main()
{
    int graph[V][V]={{0,4,0,0,0,0,0,8,0},
                    {4,0,8,0,0,0,0,11,0},
                    {0,8,0,7,0,4,0,0,2},
                    {0,0,7,0,9,14,0,0,0},
                    {0,0,0,9,0,10,0,0,0},
                    {0,0,4,14,10,0,2,0,0},
                    {0,0,0,0,0,2,0,1,6},
                    {8,11,0,0,0,0,1,0,7},
                    {0,0,2,0,0,0,6,7,0}};

    int src,dest;

    printf("\nEnter the source vertex: ");
    scanf("%d",&src);

    printf("\nEnter the destination vertex: ");
    scanf("%d",&dest);

    dijkstra(src,dest);

    return 0;
}