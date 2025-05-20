//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 100

int adj[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];

void graphColoring(int nodeCount, int colorCount)
{
    int i, j, k;
    for(i=0;i<nodeCount;i++) 
        color[i]=0;

    for(i=0;i<nodeCount;i++)
    {
        int usedColors[colorCount+1];
        for(j=0;j<=colorCount;j++)
            usedColors[j]=0;
    
        for(j=0;j<nodeCount;j++)
        {
            if(adj[i][j])
                usedColors[color[j]]=1;
        }
    
        for(j=1;j<=colorCount;j++)
        {
            if(!usedColors[j])
                break;
        }
    
        color[i]=j;
    }
} 

int main()
{
    int nodeCount, edgeCount, colorCount, i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);

    printf("Enter the number of edges: ");
    scanf("%d", &edgeCount);

    printf("Enter the adjacent matrix:\n");
    for(i=0;i<nodeCount;i++)
    {
        for(j=0;j<nodeCount;j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &colorCount);

    printf("Coloring graph ...\n");
    graphColoring(nodeCount, colorCount);

    printf("Node   Color\n");
    for(i=0;i<nodeCount;i++)
    {
        printf(" %2d       %2d\n", i, color[i]);
    }
    return 0;
}

/*
Sample Input/Output:
Enter the number of nodes: 5
Enter the number of edges: 6
Enter the adjacent matrix:
0 1 1 0 0 
1 0 1 1 0
1 1 0 1 1 
0 1 1 0 1
0 0 1 1 0
Enter the number of colors: 3
Coloring graph ...
Node   Color
 0          1
 1          2
 2          3
 3          2
 4          1
*/