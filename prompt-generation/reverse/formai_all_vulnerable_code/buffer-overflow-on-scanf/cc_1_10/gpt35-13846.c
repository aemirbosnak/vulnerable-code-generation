//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10
#define MAX_COLORS 4

int graph[MAX_NODES][MAX_NODES];
int colorings[MAX_NODES];

/* A function to check if it is safe to assign color c to vertex v*/
int isSafe(int v, int c, int n)
{
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == colorings[i])
            return 0;
    return 1;
}

/* A recursive utility function to solve graph coloring problem */
int graphColorUtil(int n, int m, int v)
{
    /* base case: If all vertices are assigned a color then return true */
    if (v == n)
        return 1;

    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++)
    {
        /* Check if assignment of color c to v is safe */
        if (isSafe(v, c, n))
        {
            colorings[v] = c;

            /* recur to assign colors to rest of the vertices */
            if (graphColorUtil(n, m, v + 1))
                return 1;

            /* If assigning color c doesn't lead to a solution then remove it */
            colorings[v] = 0;
        }
    }

    /* If no color can be assigned to this vertex then return false */
    return 0;
}

/* A function to solve graph coloring problem */
void GraphColoring(int n, int m)
{
    /* Initialize all color values as 0. This is the default value representing no color assigned to a vertex */
    for (int i = 0; i < n; i++)
        colorings[i] = 0;

    /* Call the recursive utility function to solve the available graph */
    if (graphColorUtil(n, m, 0) == 0)
    {
        printf("Solution does not exist");
        return;
    }

    /* Print the solution */
    printf("The Graph coloring Solution is:\n");
    for (int i = 0; i < n; i++)
        printf("Node %d: Color %d\n", i, colorings[i]);
}

int main()
{
    int n = 5;
    int m = 3;
    printf("Enter the number of vertices in the graph (not more than 10)\n");
    scanf("%d", &n);
    if(n > MAX_NODES){
        printf("Error: Please enter value less than %d\n", MAX_NODES);
        exit(1);
    }

    printf("Enter the number of colors to be used in the graph (not more than 4)\n");
    scanf("%d", &m);
    if(m > MAX_COLORS){
        printf("Error: Please enter value less than %d\n", MAX_COLORS);
        exit(1);
    }

    printf("Enter the Graph adjacency matrix\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    GraphColoring(n, m);
    return 0;
}