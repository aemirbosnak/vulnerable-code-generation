//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define INF 999999
#define V 8

int dist[V][V];
int parent[V][V];
int visited[V];
int start,end;

void dijkstra(int graph[V][V],int start,int end)
{
    int u,v,w;
    int min_dist=INF,min_node;

    for(int i=0;i<V;i++)
    {
        dist[start][i]=0;
        parent[start][i]=-1;
    }

    dist[start][start]=0;

    for(int count=0;count<V-1;count++)
    {
        min_dist=INF;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0&&dist[start][i]<min_dist)
            {
                min_dist=dist[start][i];
                min_node=i;
            }
        }

        visited[min_node]=1;

        for(int k=0;k<V;k++)
        {
            if(graph[min_node][k]&&visited[k]==0)
            {
                if(dist[start][min_node]+graph[min_node][k]<dist[start][k])
                {
                    dist[start][k]=dist[start][min_node]+graph[min_node][k];
                    parent[start][k]=min_node;
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for(int i=0;i<V;i++)
    {
        printf("%d \t %d\n",i,dist[start][i]);
    }

    printf("\nPath: ");
    int node=end;
    while(node!=-1)
    {
        printf("%d ",node);
        node=parent[start][node];
    }
}

int main()
{
    int graph[V][V]={{0,4,0,0,0,0,0,8},
                    {4,0,8,0,0,0,0,11},
                    {0,8,0,7,0,4,0,0},
                    {0,0,7,0,9,14,0,0},
                    {0,0,0,9,0,10,0,1},
                    {0,0,4,14,10,0,2,0},
                    {0,0,0,0,0,2,0,1},
                    {8,11,0,0,1,0,1,0}};

    int start,end;

    printf("Enter the starting vertex: ");
    scanf("%d",&start);

    printf("Enter the ending vertex: ");
    scanf("%d",&end);

    dijkstra(graph,start,end);

    return 0;
}