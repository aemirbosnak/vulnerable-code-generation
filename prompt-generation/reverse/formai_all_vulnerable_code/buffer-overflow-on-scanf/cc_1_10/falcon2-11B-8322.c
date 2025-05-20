//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to sort the elements in the given array
void bucketSort(int *arr, int size) {
    // Allocate memory for the buckets
    int **buckets = (int **) malloc(sizeof(int *) * (size + 1));
    if (buckets == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Initialize the buckets
    for (int i = 0; i <= size; i++) {
        buckets[i] = (int *) malloc(sizeof(int) * i);
        if (buckets[i] == NULL) {
            printf("Memory allocation failed!\n");
            free(buckets);
            return;
        }
    }

    // Sort the elements in each bucket
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            buckets[i][j] = arr[j];
        }
    }

    // Merge the elements from all the buckets
    int *arr2 = (int *) malloc(sizeof(int) * size);
    if (arr2 == NULL) {
        printf("Memory allocation failed!\n");
        free(buckets);
        return;
    }

    // Copy the elements from the buckets to the final array
    int i = 0, j = 0;
    for (int k = 0; k <= size; k++) {
        if (buckets[k]!= NULL) {
            for (int l = 0; l < size; l++) {
                arr2[i] = buckets[k][l];
                i++;
            }
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i <= size; i++) {
        free(buckets[i]);
    }
    free(buckets);

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, size);

    free(arr);

    return 0;
}