//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 50   // Maximum value that can be sorted
#define BUCKET_SIZE 10 // Size of the bucket array

// Function to swap two values in an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the Bucket Sort algorithm
void bucketSort(int arr[], int n)
{
    int i, j;
    int min_value = arr[0], max_value = arr[0];

    // Determine the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        } else if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Calculate the range of values to be sorted
    double range = (double)(max_value - min_value + 1) / BUCKET_SIZE;

    // Create the bucket array
    int **buckets = (int **)calloc(BUCKET_SIZE, sizeof(int *));
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *)calloc(n, sizeof(int));
    }

    // Insert the values into their respective buckets
    for (i = 0; i < n; i++) {
        int bucket_index = (int)((arr[i] - min_value) / range);
        buckets[bucket_index][i] = arr[i];
    }

    // Sort each bucket using Insertion Sort
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 1; j < n; j++) {
            if (buckets[i][j] < buckets[i][j - 1]) {
                int k = j;
                while (k > 0 && buckets[i][k] < buckets[i][k - 1]) {
                    swap(&buckets[i][k], &buckets[i][k - 1]);
                    k--;
                }
            }
        }
    }

    // Combine the buckets back into the original array
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free memory allocated for the bucket array
    for (i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Driver code
int main()
{
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random array elements
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE + 1;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}