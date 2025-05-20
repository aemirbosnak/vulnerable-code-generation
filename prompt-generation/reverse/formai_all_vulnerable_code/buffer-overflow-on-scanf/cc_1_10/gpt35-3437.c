//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // maximum number of vertices in a graph

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix to represent graph
int num_vertices; // number of vertices in the graph

int color[MAX_VERTICES]; // to store the color of each vertex
int num_colors; // number of colors used in the graph

// function to check if it is safe to color a vertex with the given color
int isSafe(int vertex, int c)
{
    for(int i=0;i<num_vertices;i++)
    {
        if(graph[vertex][i]==1 && color[i]==c)
            return 0;
    }
    return 1;
}

// recursive function to assign color to each vertex
int graphColor(int vertex)
{
    if(vertex==num_vertices) // base case: all vertices have been colored
        return 1;

    for(int c=1;c<=num_colors;c++) // try all possible colors for the vertex
    {
        if(isSafe(vertex,c)) // if it is safe to color the vertex with the given color
        {
            color[vertex]=c; // assign the color to the vertex
            if(graphColor(vertex+1)) // recursively color the next vertex
                return 1;
            color[vertex]=0; // backtracking step: unassign the color from the vertex
        }

    }
    return 0; // if no color can be assigned to the vertex, return 0
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&num_vertices);

    printf("Enter the adjacency matrix of the graph (1 if adjacent, 0 if not):\n");
    for(int i=0;i<num_vertices;i++)
    {
        for(int j=0;j<num_vertices;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter the minimum number of colors required to color the graph: ");
    scanf("%d",&num_colors);

    if(graphColor(0)) // if a valid coloring exists
    {
        printf("\n A valid coloring of the graph is: ");
        for(int i=0;i<num_vertices;i++) // print the colors assigned to each vertex
        {
            printf("%d ",color[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\n This graph cannot be colored with %d colors.\n",num_colors);
    }
    return 0;
}