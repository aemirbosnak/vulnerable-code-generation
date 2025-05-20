//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define max 100 // maximum number of vertices

int adj[max][max]; // adjacency matrix to represent the graph
int color[max]; // array to hold the color of each vertex
int n; // number of vertices in the graph

// function to check if assigning a particular color to a vertex is valid
int is_valid(int vertex, int c)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(adj[vertex][i] && color[i]==c) // if vertex is adjacent to i and i has the same color as c
        {
            return 0; // return false
        }
    }
    return 1; // return true
}

// function to assign colors to the vertices
void graph_color(int vertex)
{
    int c;
    for(c=1;c<=n;c++) // iterate over all possible colors
    {
        if(is_valid(vertex,c)) // check if assigning c to vertex is valid
        {
            color[vertex]=c; // assign c to vertex
            if(vertex+1<n)
            {
                graph_color(vertex+1); // move to next vertex
            }
            else // all vertices have been colored
            {
                // print the colored vertices
                int i;
                printf(" Colored vertices: ");
                for(i=0;i<n;i++)
                {
                    printf("Vertex %d color = %d\t", i+1, color[i]);
                }
                printf("\n");
                exit(0); // exit program
            }
        }
    }
}

int main()
{
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++) // iterate over rows
    {
        for(j=0;j<n;j++) // iterate over columns
        {
            scanf("%d",&adj[i][j]); // read the value of adj[i][j]
        }
    }
    for(i=0;i<n;i++) // initialize color array to 0
    {
        color[i]=0;
    }
    graph_color(0); // start with the first vertex
    return 0;
}