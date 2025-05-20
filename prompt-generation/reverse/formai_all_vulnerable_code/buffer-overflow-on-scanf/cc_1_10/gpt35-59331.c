//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_COLOR 1
#define MAX_COLOR 4

// function to print the graph
void printGraph(int **graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

// function to check if given color is valid for a vertex
int isValidColor(int **graph, int size, int vertex, int color, int *colorAssigned)
{
    for (int i = 0; i < size; i++)
        if (graph[vertex][i] && colorAssigned[i] == color)
            return 0;
    return 1;
}

// function to assign colors to all vertices
void assignColors(int **graph, int size)
{
    int *colorAssigned = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        colorAssigned[i] = 0;

    for (int i = 0; i < size; i++)
    {
        // Initialize possible colors for current vertex
        int possibleColors[MAX_COLOR] = {0};

        // Find all colors that are assigned to adjacent vertices
        for (int j = 0; j < size; j++)
            if (graph[i][j])
                possibleColors[colorAssigned[j]] = 1;

        // Assign the minimum possible color
        for (int j = MIN_COLOR; j <= MAX_COLOR; j++)
            if (!possibleColors[j - 1])
            {
                colorAssigned[i] = j;
                break;
            }
    }

    // Print the assigned colors
    printf("Vertex \t Color\n");
    for (int i = 0; i < size; i++)
        printf("%d\t   %d\n", i, colorAssigned[i]);
}

int main()
{
    srand(time(0));

    // Generate a random graph
    int size;
    printf("Enter the number of vertices in graph: ");
    scanf("%d", &size);

    int **graph = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        graph[i] = malloc(size * sizeof(int));

    printf("Generating a random graph...\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i != j)
                graph[i][j] = graph[j][i] = rand() % 2;
            else
                graph[i][j] = 0;
    printGraph(graph, size);

    // Assign colors to all vertices
    printf("\nAssigning colors to all vertices...\n");
    assignColors(graph, size);

    return 0;
}