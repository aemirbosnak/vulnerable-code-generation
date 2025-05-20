//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main()
{
    int n;
    int *arr;
    int i, j;
    int max_val, min_val;
    int range;
    int *bucket;
    int *sorted_arr;

    // Get number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory for input array
    arr = (int *)malloc(n * sizeof(int));

    // Get input elements from user
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calculate range of input elements
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
        else if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    range = max_val - min_val + 1;

    // Allocate memory for bucket array
    bucket = (int *)malloc(range * sizeof(int));

    // Initialize bucket array with -1
    for (i = 0; i < range; i++)
    {
        bucket[i] = -1;
    }

    // Place elements in respective buckets
    for (i = 0; i < n; i++)
    {
        j = (arr[i] - min_val) / (range / n);
        bucket[j] = i;
    }

    // Sort elements in respective buckets
    sorted_arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < range; i++)
    {
        if (bucket[i]!= -1)
        {
            sorted_arr[i] = arr[bucket[i]];
            bucket[i] = -1;
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);
    free(bucket);
    free(sorted_arr);

    return 0;
}