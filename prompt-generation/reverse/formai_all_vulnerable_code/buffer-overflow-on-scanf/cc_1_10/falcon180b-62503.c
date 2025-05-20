//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define INF 9999999
#define PI 3.14159265358979323846

int a[MAX][MAX];
int n,m;
int sx,sy,ex,ey;

int minDistance(int dist[],int sptSet[])
{
    int min=INF,min_index;
    for(int v=0;v<n;v++)
    {
        if(sptSet[v]==0 && dist[v]<=min)
        {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void printSolution(int dist[],int n)
{
    printf("Vertex\t Distance from Source\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\n",i,dist[i]);
    }
}

void dijkstra(int graph[MAX][MAX],int src)
{
    int i,j,u,v;
    int dist[MAX];
    int sptSet[MAX];
    for(i=0;i<n;i++)
    {
        dist[i]=INF;
        sptSet[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<n-1;count++)
    {
        int u=minDistance(dist,sptSet);
        sptSet[u]=1;
        for(v=0;v<n;v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u]!=INF && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    printSolution(dist,n);
}

int main()
{
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d",&n,&m);
    printf("Enter the graph:\n");
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u][v]=w;
    }
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d",&start);
    dijkstra(a,start);
    return 0;
}