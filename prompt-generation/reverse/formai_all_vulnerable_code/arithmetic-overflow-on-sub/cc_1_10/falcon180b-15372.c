//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 50
#define MAX_COLORS 6

int graph[MAX_VERTICES][MAX_VERTICES];
int num_vertices;
int num_colors;
int num_edges;
int vertices[MAX_VERTICES];
int colors[MAX_VERTICES];
int color_count[MAX_COLORS];

void init_graph(int n)
{
    srand(time(NULL));
    num_vertices = n;
    num_colors = rand() % (MAX_COLORS - 1) + 2;
    num_edges = rand() % (n * (n - 1) / 2) + n;
    for(int i = 0; i < num_edges; i++)
    {
        int v1 = rand() % num_vertices;
        int v2 = rand() % num_vertices;
        if(v1!= v2)
        {
            graph[v1][v2] = graph[v2][v1] = 1;
        }
    }
}

void print_graph()
{
    for(int i = 0; i < num_vertices; i++)
    {
        for(int j = 0; j < num_vertices; j++)
        {
            if(graph[i][j] == 1)
            {
                printf("%d - %d\n", i, j);
            }
        }
    }
}

void print_colors()
{
    for(int i = 0; i < num_vertices; i++)
    {
        printf("%d - %d\n", i, colors[i]);
    }
}

void color_graph()
{
    for(int i = 0; i < num_vertices; i++)
    {
        colors[i] = rand() % num_colors;
        color_count[colors[i]]++;
    }

    for(int i = 0; i < num_vertices; i++)
    {
        int c = colors[i];
        for(int j = 0; j < num_vertices; j++)
        {
            if(graph[i][j] == 1)
            {
                int nc = -1;
                while(nc == -1 || nc == c)
                {
                    nc = rand() % num_colors;
                }
                colors[j] = nc;
                color_count[nc]++;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph(n);
    printf("Graph:\n");
    print_graph();
    color_graph();
    printf("Colors:\n");
    print_colors();
    return 0;
}