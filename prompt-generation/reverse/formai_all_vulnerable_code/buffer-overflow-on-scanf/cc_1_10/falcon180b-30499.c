//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>

#define V 9
#define INF INT_MAX

int graph[V][V];

void addedge(int u,int v,int w)
{
    graph[u][v]=w;
    graph[v][u]=w;
}

void dijkstra(int src)
{
    int dist[V];
    bool visited[V];

    for(int i=0;i<V;i++)
    {
        dist[i]=INF;
        visited[i]=false;
    }

    dist[src]=0;

    for(int count=0;count<V-1;count++)
    {
        int u=0;

        for(int i=0;i<V;i++)
        {
            if(!visited[i] && dist[i]<=dist[u])
                u=i;
        }

        visited[u]=true;

        for(int v=0;v<V;v++)
        {
            if(!visited[v] && graph[u][v] && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }

    printf("Vertex\t Distance from Source\n");

    for(int i=0;i<V;i++)
    {
        printf("%d \t %d\n",i,dist[i]);
    }
}

int main()
{
    int graph[V][V]={
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    int source;

    printf("Enter the source vertex: ");
    scanf("%d",&source);

    dijkstra(source);

    return 0;
}