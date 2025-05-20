//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES], degree[MAX_VERTICES], color[MAX_VERTICES], num_vertices;

void graph_color(int);

int main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("\nEnter the adjacency matrix...\n");
    for(i=0;i<num_vertices;i++)
    {
        printf("\nRow %d : ", i+1);
        for(j=0;j<num_vertices;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graph_color(0);

    printf("\nVertex Colors...\n");
    for(i=0;i<num_vertices;i++)
    {
        printf("Vertex %d -> Color %d\n", i+1, color[i]);
    }

    return 0;
}

void graph_color(int vertex)
{
    int clr = 1, i;

    while(1)
    {
        color[vertex] = clr;

        for(i=0;i<num_vertices;i++)
        {
            if(graph[vertex][i] == 1 && color[i] == clr)
            {
                clr++;
                break;
            }
        }

        if(i == num_vertices)
        {
            break;
        }
    }

    if(vertex == num_vertices - 1)
    {
        return;
    }

    graph_color(vertex + 1);

    return;
}