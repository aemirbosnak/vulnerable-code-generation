//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
// C program to solve Graph Coloring Problem using Brute Force Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define Maximum number of Vertices in the Graph
#define MAX_VERTICES 100

// Define Maximum number of Colors for Coloring the Graph
#define MAX_COLORS 10

// Define the Adjacency Matrix to represent the Graph
int graph[MAX_VERTICES][MAX_VERTICES];

// Define the number of Vertices in the Graph
int num_vertices;

// Define the Color Array to store the Color assigned to each Vertex
int colors[MAX_VERTICES];

// Define the Number of Colors used to Color the Graph
int num_colors_used;

// Function Prototype to check if all the Vertices have been Colored
bool all_vertices_colored(int num_vertices, int colors[]);

// Function Prototype to check if the Proposed Color is Valid for the given Vertex
bool is_color_valid(int vertex, int color, int num_vertices, int colors[], int graph[][MAX_VERTICES]);

// Function Prototype to Color the Graph using Brute Force Algorithm
void color_graph(int vertex, int num_vertices, int colors[], int graph[][MAX_VERTICES], int num_colors, int *num_colors_used);

int main()
{
    // Read the Input Graph from the User
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &num_vertices);

    printf("\nEnter the Adjacency Matrix for the Graph:\n");
    for(int i = 0; i < num_vertices; i++)
    {
        for(int j = 0; j < num_vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all the Colors to 0 (Unassigned)
    for(int i = 0; i < num_vertices; i++)
    {
        colors[i] = 0;
    }

    // Initialize the Number of Colors used to 0
    num_colors_used = 0;

    // Call the Function to Color the Graph using Brute Force Algorithm
    color_graph(0, num_vertices, colors, graph, MAX_COLORS, &num_colors_used);

    // Print the Colored Graph
    printf("\nThe Colored Graph is:\n");
    for(int i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }

    printf("\nTotal Number of Colors used = %d\n", num_colors_used);

    return 0;
}

// Function Definition to check if all the Vertices have been Colored
bool all_vertices_colored(int num_vertices, int colors[])
{
    for(int i = 0; i < num_vertices; i++)
    {
        if(colors[i] == 0)
        {
            return false;
        }
    }
    return true;
}

// Function Definition to check if the Proposed Color is Valid for the given Vertex
bool is_color_valid(int vertex, int color, int num_vertices, int colors[], int graph[][MAX_VERTICES])
{
    // Check if the Proposed Color is not already assigned to any of the Adjacent Vertices
    for(int i = 0; i < num_vertices; i++)
    {
        if(graph[vertex][i] == 1 && colors[i] == color)
        {
            return false;
        }
    }
    return true;
}

// Function Definition to Color the Graph using Brute Force Algorithm
void color_graph(int vertex, int num_vertices, int colors[], int graph[][MAX_VERTICES], int num_colors, int *num_colors_used)
{
    // Base Case: If all the Vertices have been Colored, return
    if(all_vertices_colored(num_vertices, colors))
    {
        return;
    }

    // Try all the Possible Colors for the current Vertex
    for(int i = 1; i <= num_colors; i++)
    {
        // Check if the Proposed Color is Valid for the current Vertex
        if(is_color_valid(vertex, i, num_vertices, colors, graph))
        {
            // Assign the Proposed Color to the current Vertex
            colors[vertex] = i;

            // Update the Number of Colors used, if required
            if(i > *num_colors_used)
            {
                *num_colors_used = i;
            }

            // Recursively Color the remaining Vertices
            color_graph(vertex+1, num_vertices, colors, graph, num_colors, num_colors_used);

            // Backtrack and try with a different Color
            colors[vertex] = 0;
        }
    }
}