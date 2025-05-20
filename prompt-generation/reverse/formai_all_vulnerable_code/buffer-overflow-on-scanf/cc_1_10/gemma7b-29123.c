//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void find_minimum_distance(int **graph, int n, int m)
{
    int i, j, k, min_distance = MAX, current_distance;
    int **distance = (int *)malloc(n * sizeof(int));
    distance[0] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            current_distance = distance[i] + graph[i][j];
            if (current_distance < min_distance)
            {
                min_distance = current_distance;
            }
        }
    }

    free(distance);
    printf("The minimum distance is: %d", min_distance);
}

int main()
{
    int n, m, i, j, graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    find_minimum_distance(graph, n, m);

    return 0;
}