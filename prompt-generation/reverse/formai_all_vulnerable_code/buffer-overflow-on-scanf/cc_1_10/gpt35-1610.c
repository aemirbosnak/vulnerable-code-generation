//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_COLOR 10

int graph[MAX_VERTEX][MAX_VERTEX];
int color_map[MAX_VERTEX];

void read_graph(int num_vertex);
void print_graph(int num_vertex);
void color_graph(int num_vertex, int num_color);
int is_valid_color(int vertex, int color, int num_vertex);

int main()
{
    int num_vertex, num_color;
    
    printf("Welcome to the Graph Coloring Problem program!\n\n");
    printf("Please enter the number of vertices in your graph: ");
    scanf("%d", &num_vertex);
    
    printf("Please enter the number of colors you want to use: ");
    scanf("%d", &num_color);
    
    read_graph(num_vertex);
    printf("\nYour graph:\n\n");
    print_graph(num_vertex);
    
    color_graph(num_vertex, num_color);
    
    printf("\nYour color map:\n\n");
    for(int i=0; i<num_vertex; i++)
    {
        printf("Vertex %d: Color %d\n", i+1, color_map[i]);
    }
    
    printf("\nThank you for using our program!\n");
    
    return 0;
}

void read_graph(int num_vertex)
{
    int num_neighbours;
    int neighbour;
    
    for(int i=0; i<num_vertex; i++)
    {
        printf("Please enter the number of neighbours for vertex %d: ", i+1);
        scanf("%d", &num_neighbours);
        
        printf("Please enter the neighbours of vertex %d: ", i+1);
        for(int j=0; j<num_neighbours; j++)
        {
            scanf("%d", &neighbour);
            graph[i][neighbour-1] = 1;
        }
    }
}

void print_graph(int num_vertex)
{
    for(int i=0; i<num_vertex; i++)
    {
        printf("Vertex %d: ", i+1);
        for(int j=0; j<num_vertex; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph(int num_vertex, int num_color)
{
    int vertex;
    
    for(vertex=0; vertex<num_vertex; vertex++)
    {
        for(int color=1; color<=num_color; color++)
        {
            if(is_valid_color(vertex, color, num_vertex))
            {
                color_map[vertex] = color;
                break;
            }
                
        }
    }
}

int is_valid_color(int vertex, int color, int num_vertex)
{
    for(int i=0; i<num_vertex; i++)
    {
        if(graph[vertex][i] == 1 && color_map[i] == color)
        {
            return 0;
        }
    }
    
    return 1;
}