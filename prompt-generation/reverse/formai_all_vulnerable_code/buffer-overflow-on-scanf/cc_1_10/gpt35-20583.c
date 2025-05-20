//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int graph[MAX][MAX], color[MAX];

// checks whether a certain color can be used on a vertex
int canColor(int vertex, int c, int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        if (graph[vertex][i] && color[i] == c)
            return 0;
    }
    return 1;
}

// recursive function to assign colors to the graph vertices
int colorGraph(int nodes, int m, int vertex)
{
    if (vertex == nodes)
        return 1;
    for (int i = 1; i <= m; i++)
    {
        if (canColor(vertex, i, nodes))
        {
            color[vertex] = i;
            if (colorGraph(nodes, m, vertex + 1))
                return 1;
            color[vertex] = 0;
        }
    }
    return 0;
}

int main()
{
    int nodes, edges, option;

    printf("Enter the number of nodes and edges in the graph: ");
    scanf("%d%d", &nodes, &edges);

    // initializing the graph with 0
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = 0;
        }
        color[i] = 0;
    }

    // populating the adjacency matrix of the graph
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        printf("Enter the ends of edge %d: ", i + 1);
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Which algorithm do you want to use to color the graph? \n");
    printf("1. Backtracking Algorithm \n");
    printf("2. Greedy Algorithm \n");
    printf("Enter your option (1/2): ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Using Backtracking Algorithm to color the graph with minimum number of colors... \n");
        for (int m = 1; m <= nodes; m++)
        {
            if (colorGraph(nodes, m, 0))
            {
                printf("Minimum number of colors required to color the graph is %d \n", m);
                printf("The colors assigned to the vertices are as follows: \n");
                for (int i = 0; i < nodes; i++)
                {
                    printf("Vertex %d has color %d \n", i, color[i]);
                }
                return 0;
            }
            for (int i = 0; i < MAX; i++)
            {
                color[i] = 0;
            }
        }
        printf("Could not color the graph with less than %d colors \n", nodes);
        break;
    case 2:
        printf("Using Greedy Algorithm to color the graph... \n");
        for (int i = 0; i < nodes; i++)
        {
            int available_colors[MAX] = {0};
            for (int j = 0; j < nodes; j++)
            {
                if (graph[i][j] && color[j] != 0)
                {
                    available_colors[color[j]] = 1;
                }
            }
            int chosen_color = 1;
            while (available_colors[chosen_color])
            {
                chosen_color++;
            }
            color[i] = chosen_color;
        }
        printf("The colors assigned to the vertices are as follows: \n");
        for (int i = 0; i < nodes; i++)
        {
            printf("Vertex %d has color %d \n", i, color[i]);
        }
        break;
    default:
        printf("Invalid option selected... \n");
        break;
    }
    return 0;
}