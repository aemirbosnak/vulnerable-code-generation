//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 20

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

int main()
{
    int i, j, k, n;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        color[i] = 0;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj_matrix[i][j])
            {
                if(color[i] == color[j])
                {
                    color[j] = color[i]+1;
                }
            }
        }
    }
    
    printf("The color of each vertex is:\n");
    for(i=0;i<n;i++)
    {
        printf("Vertex %d: Color %d\n", i+1, color[i]);
    }
    
    return 0;
}