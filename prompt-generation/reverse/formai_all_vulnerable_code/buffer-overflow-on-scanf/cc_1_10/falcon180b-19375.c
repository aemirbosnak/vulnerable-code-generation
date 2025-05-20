//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int nvertices;
int chromatic_number;

void create_graph(int vertices)
{
    int i, j;
    printf("Enter %d space-separated integers to represent the graph:\n", vertices);
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void print_graph(int vertices)
{
    int i, j;
    for(i=0; i<vertices; i++)
    {
        for(j=0; j<vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph(int start_vertex, int vertices)
{
    int i, j, k, l;
    int color[vertices];
    for(i=0; i<vertices; i++)
    {
        color[i] = -1;
    }
    color[start_vertex] = 0;

    for(i=0; i<vertices; i++)
    {
        if(color[i] == -1)
        {
            for(j=0; j<vertices; j++)
            {
                if(graph[i][j] == 1)
                {
                    for(k=0; k<vertices; k++)
                    {
                        if(color[k] == -1)
                        {
                            color[k] = color[i] + 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("The chromatic number of the graph is %d\n", color[vertices-1]);
}

int main()
{
    int vertices, i;
    srand(time(NULL));
    printf("Enter the number of vertices in the graph (between 1 and 100): ");
    scanf("%d", &vertices);
    if(vertices < 1 || vertices > MAX_VERTICES)
    {
        printf("Invalid number of vertices.\n");
        return 0;
    }
    create_graph(vertices);
    color_graph(0, vertices);
    return 0;
}