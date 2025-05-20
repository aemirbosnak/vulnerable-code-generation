//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Maximum number of vertices that can be colored
#define MAX_VERTICES 100

// A function to check if a particular vertex can be colored with a particular color
bool canColor(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int color, int colors[])
{
    for(int i=0;i<MAX_VERTICES;i++)
    {
        // Check if any adjacent vertex has the same color
        if(graph[vertex][i] && colors[i]==color)
        {
            return false;
        }
    }
    return true;
}

// A function to color the graph using backtracking
bool colorGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int colors[], int vertex)
{
    // If all vertices are colored, return true
    if(vertex==vertices)
    {
        return true;
    }
    
    // Iterate over all colors to assign them to the vertex
    for(int i=1;i<=vertices;i++)
    {
        // Check if the color can be assigned to the vertex
        if(canColor(graph,vertex,i,colors))
        {
            colors[vertex]=i;
            
            // Recursively color the next vertices
            if(colorGraph(graph,vertices,colors,vertex+1))
            {
                return true;
            }
            
            // Backtrack if the current color assignment didn't work
            colors[vertex]=0;
        }
    }
    
    // Return false if all colors have been tried and none work
    return false;
}

int main()
{
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&vertices);
    
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix for the graph:\n");
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    
    // Initialize all colors to 0
    int colors[MAX_VERTICES];
    for(int i=0;i<vertices;i++)
    {
        colors[i]=0;
    }
    
    if(colorGraph(graph,vertices,colors,0))
    {
        printf("The vertices can be colored as follows:\n");
        for(int i=0;i<vertices;i++)
        {
            printf("Vertex %d: Color %d\n",i+1,colors[i]);
        }
    }
    else
    {
        printf("The vertices cannot be colored using %d colors.\n",vertices);
    }
    return 0;
}