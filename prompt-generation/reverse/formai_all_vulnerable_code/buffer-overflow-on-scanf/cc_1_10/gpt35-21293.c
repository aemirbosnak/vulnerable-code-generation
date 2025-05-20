//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
#include <stdio.h>

int main()
{
    // Declare variables
    int n, i, j;

    // Get number of vertices from user
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Create adjacency matrix using two-dimensional array
    int adjMatrix[n][n];

    // Initialize all matrix elements to 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    // Ask user to input edges
    printf("Enter the edges (Example: 0 1): (enter -1 -1 to terminate)\n");
    int u = 0, v = 0;
    while (u != -1 && v != -1)
    {
        scanf("%d %d", &u, &v);
        if (u != -1 && v != -1)
        {
            // Add edge to adjacency matrix
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    // Print out adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}