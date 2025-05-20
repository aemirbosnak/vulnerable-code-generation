//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 20

int num_vertices;
int adj_matrix[MAX_VERTICES+1][MAX_VERTICES+1];

int color_map[MAX_VERTICES+1];

int get_minimum_color(int vertex)
{
    int i, j;
    int color_available[MAX_VERTICES+1];
    int min_color;
 
    for(i=1;i<=num_vertices;++i)
        color_available[i] = 1;
 
    for(i=1;i<=num_vertices;++i)
    {
        if(adj_matrix[vertex][i] && color_map[i])
            color_available[color_map[i]] = 0;
    }
 
    for(i=1;i<=num_vertices;++i)
    {
        if(color_available[i])
        {
            min_color = i;
            break;
        }
    }
 
    for(i=1;i<=num_vertices;++i)
    {
        if(color_available[i] && i<min_color)
            min_color = i;
    }
 
    return min_color;
}
 
void assign_colors()
{
    int i,j;
    int color;
 
    color_map[1] = 1;
 
    for(i=2;i<=num_vertices;++i)
    {
        color_map[i] = 0;
    }
 
    for(i=2;i<=num_vertices;++i)
    {
        color = get_minimum_color(i);
        color_map[i] = color;
    }
}
 
int main()
{
    int i,j;
    printf("Enter the number of vertices:\n");
    scanf("%d",&num_vertices);
 
    printf("Enter the adjacency matrix:\n");
 
    for(i=1;i<=num_vertices;++i)
        for(j=1;j<=num_vertices;++j)
            scanf("%d",&adj_matrix[i][j]);
 
    assign_colors();
 
    printf("The vertices have been colored with the following colors:\n");
 
    for(i=1;i<=num_vertices;++i)
        printf("Vertex %d: Color %d\n",i,color_map[i]);
 
    return 0;
}