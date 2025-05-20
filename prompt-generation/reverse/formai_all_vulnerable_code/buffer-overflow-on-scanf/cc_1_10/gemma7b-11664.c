//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

void graphColoring(int **graph, int numVertices)
{
    int i, j, color, currentColor = 0, conflict = 0;
    int *visited = malloc(numVertices * sizeof(int));
    int *colorArray = malloc(numVertices * sizeof(int));

    for (i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
        colorArray[i] = -1;
    }

    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            if (graph[i][j] && visited[j] == 0)
            {
                for (color = 0; color < MAX_Vertices; color++)
                {
                    if (colorArray[j] != color && conflict == 0)
                    {
                        colorArray[i] = color;
                        visited[j] = 1;
                        break;
                    }
                }

                if (conflict)
                {
                    printf("No solution found.\n");
                    return;
                }
            }
        }
    }

    printf("Solution:\n");
    for (i = 0; i < numVertices; i++)
    {
        printf("Vertex %d colored with %d\n", i, colorArray[i]);
    }
}

int main()
{
    int numVertices;
    int **graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    graph = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = malloc(numVertices * sizeof(int));
    }

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    graphColoring(graph, numVertices);

    return 0;
}