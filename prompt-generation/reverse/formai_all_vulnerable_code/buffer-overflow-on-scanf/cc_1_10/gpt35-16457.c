//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
int adj[100][100],color[100],V;
void graphColoring(int pos)
{
    int i,j;
    if(pos==V)
    {
        printf("The colors used are:: ");
        for(i=0;i<V;i++)
        {
            printf("%d ",color[i]); 
        }
        printf("\n");
        return;
    }
   for(i=1;i<=4;i++)
   {
        int flag=0;
        for(j=0;j<V;j++)
        {
            if(adj[pos][j] && color[j]==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            color[pos]=i;
            graphColoring(pos+1);
            color[pos]=0;
        }
   }
}
int main() 
{
    int i,j,E,u,v;
    printf("Enter no of vertices:: ");
    scanf("%d",&V);
    printf("Enter no of edges:: ");
    scanf("%d",&E);
    printf("Enter the edges:: \n");
    for(i=0;i<E;i++)
    {
        printf("Enter edge-%d :: ",i+1);
        scanf("%d%d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
     graphColoring(0);
     return 0;
}