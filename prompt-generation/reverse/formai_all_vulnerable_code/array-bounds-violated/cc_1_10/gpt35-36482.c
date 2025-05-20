//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int num_vertices;
} set_t;

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices, num_edges;

void print_solution(int color[])
{
    printf("Coloring solution:\n");
    for(int i = 0; i < num_vertices; i++)
        printf("Vertex %d: Color %d\n", i+1, color[i]);
}

bool is_safe(int vertex, int color[], int c)
{
    for(int i = 0; i < num_vertices; i++)
        if(graph[vertex][i] && c == color[i])
            return false;
    return true;
}

bool graph_color_helper(int vertex, int color[], int num_colors)
{
    if(vertex == num_vertices)
        return true;
    for(int c = 1; c <= num_colors; c++)
    {
        if(is_safe(vertex, color, c))
        {
            color[vertex] = c;
            if(graph_color_helper(vertex+1, color, num_colors))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

bool graph_color(int num_colors)
{
    int color[num_vertices];
    for(int i = 0; i < num_vertices; i++)
        color[i] = 0;
    if(!graph_color_helper(0, color, num_colors))
    {
        printf("No solution exists with %d colors\n", num_colors);
        return false;
    }
    print_solution(color);
    return true;
}

int main()
{
    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d %d", &num_vertices, &num_edges);
    
    printf("Enter the edges (vertices to connect):\n");
    for(int i = 0; i < num_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = graph[v-1][u-1] = 1;
    }
    
    printf("Enter the maximum number of colors to use: ");
    int num_colors;
    scanf("%d", &num_colors);

    if(!graph_color(num_colors))
        return 1;
    return 0;
}