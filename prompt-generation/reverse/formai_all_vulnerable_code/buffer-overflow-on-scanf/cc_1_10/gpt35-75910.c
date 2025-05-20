//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_VERTICES 100 //Maximum vertices allowed in the graph

int num_vertices;

int adjacent_matrix[MAX_VERTICES][MAX_VERTICES];

int colors_available[MAX_VERTICES];
bool colors_used[MAX_VERTICES];

int get_min_color_availability();

void graph_coloring(); 

//Driver function
int main()
{
    int i, j;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    
    printf("Enter the adjacency matrix for the vertices: \n");
    
    for(i=0; i<num_vertices; i++)
    {
        for(j=0; j<num_vertices; j++)
        {
            scanf("%d", &adjacent_matrix[i][j]);
        }
    }
    
    graph_coloring(); //function call
    
    printf("The color assigned to each vertex of the given graph is : \n");
    
    for(i=0; i<num_vertices; i++)
    {
        printf("Vertex %d: Color %d\n", i, colors_available[i]);
    }
    
    return 0;
} 

//Function to get the color with minimum availability
int get_min_color_availability()
{
    int i, j, count, index=0;
    for(i=0; i<num_vertices; i++)
    {
        count=0;
        for(j=0; j<num_vertices; j++)
        {
            if(adjacent_matrix[i][j] == 1 && colors_used[j])
            {
                count++;
            }
        }
        if(count>=index && !colors_used[i])
        {
            index = i;
        }
    }
    return index;
}

//Function to perform the graph coloring operation
void graph_coloring()
{
    int i,j;
    
    for(i=0; i<num_vertices; i++)
    {
        colors_used[i] = false;
    }
    
    for(i=0; i<num_vertices; i++)
    {
        int min_avail = get_min_color_availability();
        
        colors_available[min_avail] = 1;
        
        for(j=0; j<num_vertices; j++)
        {
            if(adjacent_matrix[min_avail][j] == 1 && colors_used[j])
            {
                colors_available[min_avail] = colors_available[j]+1;
            }
        }
        
        colors_used[min_avail] = true;
    } 
}