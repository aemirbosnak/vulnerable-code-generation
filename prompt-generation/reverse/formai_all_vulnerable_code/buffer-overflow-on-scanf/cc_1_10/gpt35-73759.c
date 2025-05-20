//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include<stdio.h>
#define MAX 100

int graph[MAX][MAX], color_arr[MAX], V;

void print_solution()
{
     printf("The assigned colors are as follows:\n");
     for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i, color_arr[i]);
}

int is_safe(int v, int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color_arr[i])
            return 0;
    return 1;
}

int graph_color(int vertex, int color)
{
    if (vertex == V)
        return 1;

    for (int c = 1; c <= color; c++)
    {
        if (is_safe(vertex, c))
        {
            color_arr[vertex] = c;
            if (graph_color(vertex + 1, color))
                return 1;
            color_arr[vertex] = 0;
        }
    }
    return 0;
}

int main()
{
    int color;
    printf("Enter the number of vertices:");
    scanf("%d", &V);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the maximum number of colors allowed: ");
    scanf("%d", &color);

    if (graph_color(0, color))
        print_solution();
    else
        printf("No solution exists.");

    return 0;
}