//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int main()
{
    int i, j, k, n, m;
    char **graph;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (char *)malloc(MAX * sizeof(char));
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter the source node: ");
        scanf("%d", &k);

        printf("Enter the destination node: ");
        scanf("%d", &j);

        graph[k][j] = 1;
    }

    printf("The network topology map is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d - ", j);
            }
        }

        printf("\n");
    }

    return 0;
}