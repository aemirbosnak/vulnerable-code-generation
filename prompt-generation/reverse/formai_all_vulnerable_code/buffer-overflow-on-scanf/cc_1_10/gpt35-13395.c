//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX 100
 
void dijkstra(int G[MAX][MAX], int n, int startnode);

void A_star(int graph[MAX][MAX],int n,int startnode,int endnode)
{
    int v[MAX],d[MAX],parent[MAX];
    int i,j,navigation,k,min_dis,nextnode;
    int heuristic[MAX][MAX];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph[i][j]==0)
                heuristic[i][j]=INFINITY;
            else
                heuristic[i][j]=graph[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        d[i]=heuristic[startnode][i];
        parent[i]=startnode;
        v[i]=0;
    }
    d[startnode]=0;
    v[startnode]=1;
    navigation=startnode;
    while(navigation!=endnode)
    {
        min_dis=INFINITY;
        for(i=0;i<n;i++)
        {
            if(min_dis>d[i] && !v[i])
            {
                min_dis=d[i];
                nextnode=i;
            }
        }
        if(min_dis==INFINITY)
            break;
        v[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if(!v[i])
            {
                if(min_dis+heuristic[nextnode][i]<d[i])
                {
                    d[i]=min_dis+heuristic[nextnode][i];
                    parent[i]=nextnode;
                }
            }
        }
        navigation=nextnode;
    }
    printf("\nDistance : %d\n",d[endnode]);
    printf("\nPath : %d",endnode);
    j=endnode;
    do
    {
        j=parent[j];
        printf("<-%d",j);
    }while(j!=startnode);
}

int main()
{
    int G[MAX][MAX],n,u,start,end;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    printf("\nEnter the starting node:");
    scanf("%d",&start);

    printf("\nEnter the ending node:");
    scanf("%d",&end);

    A_star(G,n,start,end);

    return 0;
}