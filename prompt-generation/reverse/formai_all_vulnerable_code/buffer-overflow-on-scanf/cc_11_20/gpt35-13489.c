//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_DEGREE 50

int graph[MAX_VERTICES][MAX_DEGREE];
int colors[MAX_VERTICES]; 
int n_vertices, n_colors;

int main()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n_vertices);

    printf("Enter the color choices: ");
    scanf("%d", &n_colors);

    // initializing the graph with all 0s
    for(i=0; i<n_vertices; i++) 
    {
        for(j=0; j<MAX_DEGREE; j++)
        {
            graph[i][j] = 0;
        }
    }

    // getting the adjacency list
    for(i=0; i<n_vertices; i++)
    {
        int n_adjacent;
        printf("Enter number of vertices adjacent to vertex %d: ", i+1);
        scanf("%d", &n_adjacent);

        for(j=0; j<n_adjacent; j++)
        {
            int adjacent;
            printf("Enter the index of adjacent vertex %d: ", j+1);
            scanf("%d", &adjacent);
            graph[i][j] = adjacent-1;
        }
        graph[i][j] = -1; // mark the end of the list
    }

    // start the graph coloring algorithm
    for(i=0; i<n_vertices; i++)
    {
        int available_colors[n_colors];

        // initializing the available colors array
        for(j=0; j<n_colors; j++)
        {
            available_colors[j] = 0;
        }

        // checking the colors used by the adjacent vertices
        for(j=0; graph[i][j] != -1; j++) 
        {
            int adjacent_vertex = graph[i][j];
            if(colors[adjacent_vertex] != 0)
            {
                available_colors[colors[adjacent_vertex]-1] = 1;
            }
        }

        // assigning the minimum available color to the vertex
        for(j=0; j<n_colors; j++) 
        {
            if(available_colors[j] == 0)
            {
                colors[i] = j+1;
                break;
            }
        }
    }

    //printing the final color assignments
    printf("The vertex colors are: ");
    for(i=0; i<n_vertices; i++)
    {
        printf("%d ", colors[i]);
    }

    return 0;
}