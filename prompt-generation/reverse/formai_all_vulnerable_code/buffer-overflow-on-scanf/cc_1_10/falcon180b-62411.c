//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000000

void bucket_sort(int *arr, int size)
{
    int i, j;
    int *bucket[MAX_SIZE];
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    for (i = 0; i < size; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
        else if (arr[i] < min_val)
            min_val = arr[i];
    }

    int range = max_val - min_val + 1;
    int bucket_size = range / size;

    for (i = 0; i < size; i++)
    {
        bucket[i] = (int *) malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < size; i++)
    {
        int index = (arr[i] - min_val) / bucket_size;
        bucket[index] = realloc(bucket[index], (index + 1) * sizeof(int));
        bucket[index][index] = arr[i];
    }

    int k = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < bucket_size; j++)
        {
            if (bucket[i][j]!= INT_MIN)
            {
                arr[k] = bucket[i][j];
                k++;
            }
        }
    }
}

int main()
{
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *) malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}