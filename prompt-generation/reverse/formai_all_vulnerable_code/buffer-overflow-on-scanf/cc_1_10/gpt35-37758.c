//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 100

// Function prototypes
void input_graph(int mat[][MAX_VERTEX], int *n, int *e);
void print_graph(int mat[][MAX_VERTEX], int n, int e);
void graph_coloring(int mat[][MAX_VERTEX], int n);
int is_safe(int mat[][MAX_VERTEX], int color[], int n, int vertex, int c);

int main()
{
    int mat[MAX_VERTEX][MAX_VERTEX], n, e;

    input_graph(mat, &n, &e);
    printf("\n\nThe entered graph is:\n");
    print_graph(mat, n, e);

    graph_coloring(mat, n);

    return 0;
}

// Function to take input a graph as adjacency matrix
void input_graph(int mat[][MAX_VERTEX], int *n, int *e)
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", n);

    printf("Enter the number of edges: ");
    scanf("%d", e);

    // Initialize all elements of the matrix to 0
    for(i=0;i<*n;i++)
    {
        for(j=0;j<*n;j++)
            mat[i][j] = 0;
    }

    // Enter the edges
    printf("Enter the edges (in pair of vertices):\n");
    for(i=0;i<*e;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        mat[u][v] = mat[v][u] = 1;
    }
}

// Function to print the graph
void print_graph(int mat[][MAX_VERTEX], int n, int e)
{
    int i, j;

    // Print the adjacency matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function to perform graph coloring
void graph_coloring(int mat[][MAX_VERTEX], int n)
{
    int color[MAX_VERTEX], i;

    // Initialize all elements of color array to 0
    for(i=0;i<n;i++)
        color[i] = 0;

    // Assign the first color to the first vertex
    color[0] = 1;

    // Perform graph coloring recursively
    if(is_safe(mat, color, n, 1, 0) == 0)
        printf("\nGraph cannot be colored with 2 colors!\n");
    else
    {
        printf("\nGraph can be colored with 2 colors as follows:\n");
        for(i=0;i<n;i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

// Function to check if a particular color can be assigned to a vertex
int is_safe(int mat[][MAX_VERTEX], int color[], int n, int vertex, int c)
{
    int i;

    // Check if the color is already assigned to any adjacent vertex
    for(i=0;i<n;i++)
    {
        if(mat[vertex][i] && color[i] == c)
            return 0;  // Color is not safe
    }

    // If all adjacent vertices have distinct colors, assign the color to the current vertex
    color[vertex] = c;

    // Recursively assign colors to all remaining vertices
    for(i=0;i<n;i++)
    {
        if(mat[vertex][i] && color[i] == 0)
        {
            if(is_safe(mat, color, n, i, 3-c) == 0)
                return 0;  // Color is not safe
        }
    }

    return 1;  // Color is safe
}