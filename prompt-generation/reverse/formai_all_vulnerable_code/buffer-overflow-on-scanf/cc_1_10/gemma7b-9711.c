//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
{
    int i, j, h, bucket[k], *p, **q;
    q = (int **)malloc(k * sizeof(int *));
    for (i = 0; i < k; i++)
        q[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        p = arr[i];
        h = *p % k;
        q[h][i] = p;
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] != NULL)
            {
                arr[j] = q[i][j];
            }
        }
    }

    free(q);
}

int main()
{
    int **arr = NULL, n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the number of buckets: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(sizeof(int));

    bucket_sort(arr, n, k);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}