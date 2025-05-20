//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, j, k, n, m;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the number of edges:");
    scanf("%d", &m);

    // Create the adjacency list
    int **adjList = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        adjList[i] = (int*)malloc(m * sizeof(int));
    }

    // Enter the edge list
    for (i = 0; i < m; i++)
    {
        printf("Enter the source node:");
        scanf("%d", &k);
        printf("Enter the destination node:");
        scanf("%d", &j);
        adjList[k][j] = 1;
    }

    // Print the adjacency list
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adjList[i][j] != 0)
            {
                printf("%d ", adjList[i][j]);
            }
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(adjList[i]);
    }
    free(adjList);

    return 0;
}