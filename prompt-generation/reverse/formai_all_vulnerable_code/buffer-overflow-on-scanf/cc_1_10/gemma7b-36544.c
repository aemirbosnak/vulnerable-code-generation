//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void paranoid_bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, bucket_num = 0;
    int *buckets = NULL;

    buckets = malloc(n * sizeof(int));
    memset(buckets, 0, n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        buckets[k]++;
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (buckets[i] > 0)
        {
            bucket_size = buckets[i];
            bucket_num++;
            printf("Bucket %d has %d elements:\n", bucket_num, bucket_size);
            for (j = 0; j < bucket_size; j++)
            {
                printf("Element %d: %d\n", j + 1, arr[bucket_num * (j) - 1]);
            }
            printf("\n");
        }
    }

    free(buckets);
}

int main()
{
    int n, i, **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    paranoid_bucket_sort(arr, n);

    free(arr);

    return 0;
}