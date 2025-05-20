//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void distance(int **a, int **b, int n)
{
    int i, j, d = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d = abs((*a)[i] - (*b)[j]) + abs((*a)[i] - (*b)[j]) + abs((*a)[i] - (*b)[j]);
            printf("Distance between (%d, %d) and (%d, %d) is: %d\n", (*a)[i], (*a)[i], (*b)[j], (*b)[j], d);
        }
    }
}

int main()
{
    int **a = NULL;
    int **b = NULL;
    int n = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the elements to be clustered: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    distance(a, b, n);

    free(a);
    free(b);

    return 0;
}