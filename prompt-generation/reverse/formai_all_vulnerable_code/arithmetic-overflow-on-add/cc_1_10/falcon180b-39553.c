//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define NODES 9
#define INF INT_MAX

int dist[NODES][NODES];
int parent[NODES][NODES];

void init(int graph[NODES][NODES])
{
    int i,j;
    for(i=0;i<NODES;i++)
    {
        for(j=0;j<NODES;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }
}

void floydwarshall(int graph[NODES][NODES])
{
    int i,j,k;
    for(k=0;k<NODES;k++)
    {
        for(i=0;i<NODES;i++)
        {
            for(j=0;j<NODES;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    parent[i][j]=k;
                }
            }
        }
    }
}

void printSolution(int parent[NODES][NODES],int n1,int n2)
{
    if(parent[n1][n2]!=-1)
    {
        printSolution(parent,n1,parent[n1][n2]);
        printf("%d ",n2);
    }
}

int main()
{
    int graph[NODES][NODES]={{0,4,INF,INF,INF,INF,INF,INF,INF},
                             {INF,0,3,INF,1,INF,INF,INF,INF},
                             {INF,INF,INF,0,INF,INF,2,INF,INF},
                             {INF,INF,INF,INF,0,5,INF,INF,INF},
                             {INF,1,INF,INF,INF,0,INF,INF,INF},
                             {INF,INF,2,INF,INF,INF,0,INF,INF},
                             {INF,INF,INF,5,INF,INF,INF,0,INF},
                             {INF,INF,INF,INF,INF,INF,INF,INF,1},
                             {INF,INF,INF,INF,INF,INF,INF,INF,INF}};

    init(graph);
    floydwarshall(graph);

    int source,destination;
    printf("Enter source and destination nodes: ");
    scanf("%d %d",&source,&destination);

    if(dist[source][destination]==INF)
        printf("No path exists.\n");
    else
    {
        printf("Shortest path: ");
        printSolution(parent,source,destination);
    }

    return 0;
}