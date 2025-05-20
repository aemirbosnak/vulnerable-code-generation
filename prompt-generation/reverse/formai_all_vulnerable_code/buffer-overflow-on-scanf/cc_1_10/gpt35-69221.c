//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

int colors[100]; // to store the colors assigned to vertices
int dimension = 0; // dimension of the graph

int isSafe(int v,int graph[][dimension], int color, int colorsAssigned[]) // function to determine if color can be assigned to a vertex
{
    for(int i=0;i<dimension;i++)
    {
        // check if adjacent vertices have same color
        if(graph[v][i] == 1 && colorsAssigned[i] == color)
        {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int graph[][dimension], int m , int v) // function to assign colors to vertices
{
    // base case
    if(v == dimension)
    {
        return 1;
    }
    
    // check if color can be assigned to vertex
    for(int color = 1;color<=m;color++)
    {
        if(isSafe(v,graph,color,colors)) // if safe to assign color
        {
            colors[v] = color; // assign color to vertex
            
            if(graphColoring(graph,m, v+1) == 1) // recursive call
            {
                return 1;
            }
            
            colors[v] = 0; // backtrack
        }
    }
    return 0;
}

int main()
{
    printf("Enter the dimension of the graph : ");
    scanf("%d",&dimension);
    
    int graph[100][100];
    
    printf("Enter the adjacency matrix : \n");
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    
    int m; // maximum number of colors
    
    printf("Enter the maximum number of colors : ");
    scanf("%d",&m);
    
    // initialize colors array with all zeros
    for(int i=0;i<dimension;i++)
    {
        colors[i] = 0;
    }
    
    if(graphColoring(graph, m, 0) == 0) // function call to assign colors
    {
        printf("Solution does not exist");
    }
    
    else
    {
        printf("Possible solution : \n");
        for(int i=0;i<dimension;i++)
        {
            printf("Vertex %d has color %d\n",i+1,colors[i]);
        }
    }
    
    return 0;
}