//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define INF INT_MAX
#define V 4
#define E 5

int graph[V][V];
int dist[V];
int parent[V];

void dijkstra(int spt)
{
    int u,v,i,min;
    for(u=0;u<V;u++)
    {
        dist[u]=INF;
        parent[u]=-1;
    }
    dist[spt]=0;
    for(i=0;i<V-1;i++)
    {
        min=INF;
        for(u=0;u<V;u++)
        {
            for(v=0;v<V;v++)
            {
                if(dist[u]+graph[u][v]<dist[v])
                {
                    dist[v]=dist[u]+graph[u][v];
                    parent[v]=u;
                }
            }
        }
    }
}

void printSolution(int n)
{
    int v=n-1;
    printf("\nVertex\t Distance from Source\tPath");
    for(int i=0;i<V;i++)
    {
        printf("\n%d \t\t %d \t\t",i,dist[i]);
        if(parent[i]!=-1)
        {
            printf("->");
        }
    }
}

int main()
{
    int graph[V][V]={{0,2,0,6,0},{INF,0,3,8,5},{INF,INF,0,0,7},{INF,INF,INF,0,9},{INF,INF,INF,INF,0}};
    int source;
    printf("Enter the source vertex: ");
    scanf("%d",&source);
    dijkstra(source);
    printSolution(V);
    return 0;
}