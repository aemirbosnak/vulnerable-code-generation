//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, p, q, r, t;
    int **arr;
    int **heap;
    int **visited;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    heap = (int **)malloc(n * sizeof(int *));
    visited = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
        heap[i] = (int *)malloc(MAX * sizeof(int));
        visited[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of children for node %d: ", i);
        scanf("%d", &k);

        for (j = 0; j < k; j++)
        {
            printf("Enter the child's index of node %d: ", i);
            scanf("%d", &p);

            arr[i][p] = 1;
        }
    }

    printf("Enter the root node index: ");
    scanf("%d", &r);

    t = heap[r];

    while (t)
    {
        printf("Node %d is visited\n", t);
        visited[t] = 1;

        for (i = 0; i < MAX; i++)
        {
            if (arr[t][i] && !visited[i])
            {
                heap[t] = i;
                break;
            }
        }

        t = heap[t];
    }

    return 0;
}