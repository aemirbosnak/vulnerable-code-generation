//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compare two integers
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    else
        return 0;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j;
    int *bucket[MAX_SIZE];

    // Initialize all buckets to NULL
    for (i = 0; i < MAX_SIZE; i++)
        bucket[i] = NULL;

    // Insert each element into its respective bucket
    for (i = 0; i < n; i++) {
        int index = arr[i] * MAX_SIZE / (n - 1);
        if (bucket[index] == NULL) {
            bucket[index] = (int *)malloc(sizeof(int));
            *bucket[index] = arr[i];
        } else {
            int *temp = (int *)realloc(bucket[index], sizeof(int) * 2);
            if (temp == NULL) {
                printf("Memory error\n");
                exit(0);
            }
            bucket[index] = temp;
            *(temp + 1) = arr[i];
        }
    }

    // Concatenate all buckets back into the original array
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            int k;
            for (k = 0; k < *(int *)bucket[j]; k++) {
                arr[i++] = *((int *)bucket[j] + k);
            }
            free(bucket[j]);
            bucket[j] = NULL;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}