//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE_SIZE 100

void bucket_sort(int arr[], int n)
{
    int i, j, range, size, pos, count[MAX_SIZE] = {0};
    int *out, *temp;

    // Calculate the range of the array
    range = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > range)
            range = arr[i];
    }

    // Calculate the size of each bucket
    size = range / RANGE_SIZE;

    // Create an array of empty buckets
    out = (int *)malloc(n * sizeof(int));

    // Place each element in its corresponding bucket
    for (i = 0; i < n; i++) {
        pos = arr[i] / size;
        count[pos]++;
    }

    for (i = 0; i < n; i++) {
        pos = arr[i] / size;
        out[count[pos] - 1] = arr[i];
        count[pos]--;
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < n; i++) {
        arr[i] = out[i];
    }

    // Free the memory allocated for the output array
    free(out);
}

int main()
{
    int n, i;
    int arr[MAX_SIZE];

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate random numbers between 0 and 1000
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}