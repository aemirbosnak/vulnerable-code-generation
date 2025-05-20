//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 //maximum number of vertices in the graph
#define MAX_COLORS 10 //maximum number of colors

int graph[MAX_VERTICES][MAX_VERTICES]; //adjacency matrix of the graph
int num_vertices; //number of vertices in the graph

int color_graph(int colors[])
{
    int col, color, max_color=0;
    for(int i=0; i<num_vertices; i++)
    {
        col = 1; //initial color
        while(1)
        {
            color = 1;
            while(color<col)
            {
                if(graph[i][color] && colors[i]==color) //conflicting color found
                    break;
                color++;
            }
            if(color==col) //found a suitable color
            {
                colors[i] = col;
                if(col>max_color)
                    max_color = col;
                break;
            }
            col++; //try the next color
        }
    }
    return max_color;
}

int main()
{
    int num_edges, u, v;
    int colors[MAX_VERTICES] = {0}; //initialize all vertices to color 0
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);
    printf("Enter the edges connecting two vertices:\n");
    for(int i=0; i<num_edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    int max_color = color_graph(colors);
    printf("Minimum number of colors required to color the graph: %d\n", max_color);
    printf("Coloring of each vertex:\n");
    for(int i=0; i<num_vertices; i++)
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    return 0;
}