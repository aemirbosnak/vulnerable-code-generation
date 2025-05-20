//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Function to perform bucket sort */
void bucketSort(int arr[], int n) {
    int i, j, k, max = arr[0], min = arr[0];

    /* Find the maximum and minimum values in the array */
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    /* Calculate the range of the array */
    int range = max - min + 1;

    /* Create an array of empty buckets */
    int bucket[MAX_SIZE] = {0};

    /* Place each element in its respective bucket */
    for (i = 0; i < n; i++) {
        k = (arr[i] - min) / range;
        bucket[k]++;
    }

    /* Modify the bucket counts to get the correct positions of elements */
    for (i = 1; i < MAX_SIZE; i++) {
        bucket[i] += bucket[i - 1];
    }

    /* Place the elements back in the original array */
    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] - min) / range;
        bucket[j]--;
        arr[bucket[j]] = arr[i];
    }
}

/* Function to print an array */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Main function */
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    /* Allocate memory for the array */
    int *arr = (int *)malloc(n * sizeof(int));

    /* Check if memory allocation was successful */
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    /* Get the elements from the user */
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Sort the array using bucket sort */
    bucketSort(arr, n);

    /* Print the sorted array */
    printf("Sorted array:\n");
    printArray(arr, n);

    /* Free the memory allocated for the array */
    free(arr);

    return 0;
}