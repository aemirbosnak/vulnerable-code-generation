//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#define max_num 10 

int graph[max_num][max_num], num_vertices;

int color[max_num]; // it is used to keep track of colors of all the vertices
int available_colors[max_num];

int max_degree_vertex() // function to find out the vertex which has maximum degree
{
    int i, j, degree, max_degree=-1, max_degree_index;
    for(i=0; i<num_vertices; i++)
    {
        degree = 0;
        for(j=0; j<num_vertices; j++)
            if(graph[i][j])
                degree++;       
        if(degree>max_degree && color[i]==-1) // to check if a vertex has already been colored or not
        {
            max_degree = degree;
            max_degree_index = i;
        }
    }
    return max_degree_index;
}

void available_colors_list(int vertex) // function to create the list of available colors for a vertex
{
    int i;
    for(i=0; i<num_vertices; i++)
        if(graph[vertex][i] && color[i]!=-1) // to check if a color has already been assigned to neighboring vertices
            available_colors[color[i]] = 1;
}

void graph_coloring(int vertex) // function to color the vertices
{
    int i, j;
    if(vertex==-1) // if all the vertices are colored
    {
        printf("Vertex \tColor\n");
        for(i=0; i<num_vertices; i++)
            printf("%d \t%d\n", i, color[i]);
        exit(0);
    }
    
    available_colors_list(vertex);

    for(i=0; i<num_vertices; i++)
        if(!available_colors[i]) // if the color is not used by neighboring vertices, it is available
        {
            color[vertex] = i;
            graph_coloring(max_degree_vertex());
            color[vertex] = -1; // backtracking
        }
}

int main()
{
    int i, j, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    for(i=0; i<num_vertices; i++)
        for(j=0; j<num_vertices; j++)
            graph[i][j] = 0; // to initialize all the elements of the graph matrix to 0
            
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for(i=0; i<edges; i++)
    {
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1; // undirected graph
    }
    
    for(i=0; i<num_vertices; i++)
        color[i] = -1; // to initialize all the vertices to uncolored(-1) state
    
    graph_coloring(max_degree_vertex()); // calling graph coloring function
    
    return 0;
}