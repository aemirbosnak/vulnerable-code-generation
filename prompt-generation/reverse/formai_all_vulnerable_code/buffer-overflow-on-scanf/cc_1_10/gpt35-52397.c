//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 10000

int edges[MAX_EDGES][2];  // Array to store edges
int colors[MAX_VERTICES]; // Array to store colors
int num_vertices, num_edges, num_colors;

// Function to read input from console
void read_input()
{
    scanf("%d %d %d", &num_vertices, &num_edges, &num_colors);
    
    for(int i=0; i<num_edges; i++)
    {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
}

// Function to check if a vertex can be colored with a given color
bool can_color(int vertex, int color)
{
    for(int i=0; i<num_edges; i++)
    {
        if(edges[i][0] == vertex && colors[edges[i][1]] == color)
        {
            return false;
        }
        
        if(edges[i][1] == vertex && colors[edges[i][0]] == color)
        {
            return false;
        }
    }
    
    return true;
}

// Function to color a vertex
bool color_vertex(int vertex)
{
    if(vertex == num_vertices)
    {
        return true; // All vertices have been colored
    }
    
    for(int color=1; color<=num_colors; color++)
    {
        if(can_color(vertex, color))
        {
            colors[vertex] = color;
            
            if(color_vertex(vertex+1))
            {
                return true; // Color found
            }

            colors[vertex] = 0; // Backtrack
        }
    }
    
    return false; // Color not found
}

// Function to print the final colors of vertices
void print_colors()
{
    printf("Colors:\n");
    
    for(int i=0; i<num_vertices; i++)
    {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
}

int main()
{
    read_input();
    
    if(color_vertex(0))
    {
        printf("Solution found!\n");
        print_colors();
    }
    else
    {
        printf("Solution not found!\n");
    }
    
    return 0;
}