//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main()
{
    int n, i, j, k, max, min, range;
    int *arr;
    float *bucket;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));
    bucket = (float *) malloc(n * sizeof(float));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    range = max - min + 1;

    printf("Enter the number of buckets: ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        bucket[i] = min + (i * range) / (k - 1);
        printf("Bucket %d: %f\n", i + 1, bucket[i]);
    }

    for (i = 0; i < n; i++)
    {
        j = (int) ((arr[i] - min) * (k - 1) / range);
        if (j == k - 1)
        {
            bucket[j] += 1;
        }
        else
        {
            bucket[j] += 1;
            bucket[j + 1] -= 1;
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}