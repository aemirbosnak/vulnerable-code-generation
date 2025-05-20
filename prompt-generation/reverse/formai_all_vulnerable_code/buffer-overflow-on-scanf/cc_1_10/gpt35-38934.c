//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include<stdio.h>
#include<limits.h>
#define ROW 10
#define COL 10
#define VERTEX 100

/* A function to find the shortest path between two vertices using Dijkstra's algorithm */
void dijkstra_algo(int graph[VERTEX][VERTEX], int src, int dest)
{
    int dist[VERTEX], visited[VERTEX], i, j, minDist, nextVertex;
    for(i=0;i<VERTEX;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[src]=0;
    for(i=0;i<VERTEX;i++)
    {
        minDist=INT_MAX;
        for(j=0;j<VERTEX;j++)
        {
            if(dist[j]<minDist && visited[j]==0)
            {
                minDist=dist[j];
                nextVertex=j;
            }
        }
        visited[nextVertex]=1;
        for(j=0;j<VERTEX;j++)
        {
            if(visited[j]==0 && graph[nextVertex][j]>0 && dist[nextVertex]+graph[nextVertex][j]<dist[j])
            {
                dist[j]=dist[nextVertex]+graph[nextVertex][j];
            }
        }
    }
    printf("Shortest path between vertex %d and vertex %d is: %d\n",src,dest,dist[dest]);
}

/* Main function */
int main()
{
    int i, j, numVertices, graph[VERTEX][VERTEX], src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d",&numVertices);
    printf("Enter the adjacency matrix: ");
    for(i=0;i<numVertices;i++)
    {
        for(j=0;j<numVertices;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d",&src);
    printf("Enter the destination vertex: ");
    scanf("%d",&dest);
    dijkstra_algo(graph,src,dest);
    return 0;
}