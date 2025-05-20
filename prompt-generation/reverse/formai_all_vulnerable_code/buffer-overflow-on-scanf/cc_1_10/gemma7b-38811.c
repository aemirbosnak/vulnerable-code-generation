//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
{
    int i, j, h, bucket[k], *p = *arr;

    for (i = 0; i < n; i++)
    {
        bucket[p[i]]++;
    }

    for (h = 0; h < k; h++)
    {
        if (bucket[h] > 0)
        {
            for (j = 0; j < bucket[h]; j++)
            {
                p[i] = h + 1;
                i++;
            }
        }
    }
}

int main()
{
    int n, k, i, arr[100];

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the number of buckets:");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucket_sort(&arr, n, k);

    printf("The sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}