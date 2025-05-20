//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int n, i, j, k, l, r, c = 0;
    char **graph = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
    {
        graph[i] = (char*)malloc(n * sizeof(char));
        for(j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &r);

    for(i = 0; i < r; i++)
    {
        printf("Enter the source node: ");
        scanf("%d", &k);

        printf("Enter the destination node: ");
        scanf("%d", &l);

        graph[k][l] = 1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
            {
                c++;
            }
        }
    }

    printf("The number of connected components is: %d", c);

    return 0;
}