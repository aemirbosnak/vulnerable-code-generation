//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucketSort(int **arr, int n)
{
    int i, j, k, bucket[MAX], count[MAX] = {0};

    for (i = 0; i < n; i++)
    {
        bucket[*arr[i]]++;
    }

    for (j = 0; j < MAX; j++)
    {
        count[j] += count[j - 1];
    }

    int output[n];

    for (k = n - 1; k >= 0; k--)
    {
        output[count[*arr[k]] - 1] = *arr[k];
        count[*arr[k]]--;
    }

    for (i = 0; i < n; i++)
    {
        *arr[i] = output[i];
    }
}

int main()
{
    int n, i, arr[MAX];

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}