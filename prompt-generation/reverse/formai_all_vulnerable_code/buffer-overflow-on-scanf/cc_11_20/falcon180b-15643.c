//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int i, n;
    int *arr;
    int *buckets[MAX_SIZE];
    int max, min;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Calculate the range of the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min) / (max - min) * MAX_SIZE;
        int j = 0;
        while (j < MAX_SIZE && buckets[j][0]!= 0) {
            j++;
        }
        buckets[j][0] = arr[i];
        buckets[j][1]++;
    }

    // Sort the elements in each bucket
    for (i = 0; i < MAX_SIZE; i++) {
        if (buckets[i][0]!= 0) {
            int j = 0;
            while (j < buckets[i][1]) {
                int k = 0;
                while (k < buckets[i][1] - 1 && arr[j] <= arr[j + 1]) {
                    k++;
                }
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                j++;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory
    for (i = 0; i < MAX_SIZE; i++) {
        free(buckets[i]);
    }
    free(arr);

    return 0;
}