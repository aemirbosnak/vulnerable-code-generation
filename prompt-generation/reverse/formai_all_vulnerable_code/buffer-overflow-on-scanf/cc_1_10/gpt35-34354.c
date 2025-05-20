//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n; // number of vertices

void printSolution()
{
    printf("Vertex Colors:\n");
    for(int i=0; i<n; i++)
        printf("Vertex %d: %d\n", i+1, color[i]);
}

void greedyColoring()
{
    color[0] = 0;
    for(int i=1; i<n; i++)
        color[i] = -1;

    for(int i=1; i<n; i++)
    {
        int availableColors[MAX_VERTICES] = {0};

        for(int j=0; j<i; j++)
        {
            if(graph[i][j] && color[j] != -1)
                availableColors[color[j]] = 1;
        }

        int c;
        for(c=0; c<i; c++)
            if(!availableColors[c])
                break;

        color[i] = c;
    }

    printSolution();
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    printf("\nColoring:\n");
    greedyColoring();

    return 0;
}