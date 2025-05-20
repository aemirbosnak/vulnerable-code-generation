//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Dennis Ritchie
// C program to solve the Graph Coloring Problem

#include <stdio.h>

#define MAX 100

int adj_matrix[MAX][MAX];
int vertex_color[MAX];
int num_vertices, num_edges;

void initialize()
{
    int i, j;
    for(i=0;i<num_vertices;i++)
    {
        vertex_color[i] = 0;
        for(j=0;j<num_vertices;j++)
            adj_matrix[i][j] = 0;
    }
}

void read_graph()
{
    printf("Enter number of vertices: ");
    scanf("%d",&num_vertices);

    printf("Enter number of edges: ");
    scanf("%d",&num_edges);

    initialize();

    int i, j, u, v;
    printf("Enter edges: \n");
    for(i=0;i<num_edges;i++)
    {
        scanf("%d %d",&u,&v);
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
}

int can_color(int v, int c)
{
    int i;
    for(i=0;i<num_vertices;i++)
    {
        if(adj_matrix[v][i] && vertex_color[i] == c)
            return 0;
    }
    return 1;
}

int solve_graph_coloring(int vertex)
{
    int c;
    for(c=1;c<=num_vertices;c++)
    {
        if(can_color(vertex, c))
        {
            vertex_color[vertex] = c;
            if(vertex == num_vertices-1)
                return 1;
            else if(solve_graph_coloring(vertex+1))
                return 1;
            vertex_color[vertex] = 0;
        }
    }
    return 0;
}

void display_output()
{
    int i;
    printf("Vertex   Color\n");
    for(i=0;i<num_vertices;i++)
        printf("%d         %d\n",i+1,vertex_color[i]);
}

int main()
{
    read_graph();
    if(solve_graph_coloring(0))
        display_output();
    else
        printf("Solution does not exist.\n");
    return 0;
}