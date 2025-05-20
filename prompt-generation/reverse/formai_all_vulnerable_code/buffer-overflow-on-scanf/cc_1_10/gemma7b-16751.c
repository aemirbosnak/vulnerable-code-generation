//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cluster(int **a, int n)
{
    int i, j, k, l, d, **b, **c;
    b = (int *)malloc(n * sizeof(int));
    c = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        b[i] = -1;
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                d = abs(a[i] - a[j]);
                if (b[j] == -1 || d < c[j])
                {
                    c[j] = d;
                    b[j] = i;
                }
            }
        }
    }
    for (k = 0; k < n; k++)
    {
        l = b[k];
        printf("The cluster of %d is %d.\n", a[k], a[l]);
    }
    free(b);
    free(c);
}

int main()
{
    int n, i, **a;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    cluster(a, n);
    free(a);
    return 0;
}