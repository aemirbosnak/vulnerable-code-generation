//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum number of elements in the array
#define MAX_VALUE 100 // Maximum value of an element in the array

int main() {
    int arr[MAX_SIZE];
    int n;
    int i, j;
    int count[MAX_VALUE + 1] = {0}; // Count array to keep track of the frequency of each element
    int max = 0; // Maximum value in the array
    int min = MAX_VALUE; // Minimum value in the array

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) { // Update the maximum value in the array
            max = arr[i];
        }
        if (arr[i] < min) { // Update the minimum value in the array
            min = arr[i];
        }
        count[arr[i]]++; // Increment the frequency of the element in the count array
    }

    // Create the buckets based on the range of the elements in the array
    int range = max - min + 1;
    int bucket_size = range / n;
    int *buckets[n];
    for (i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    // Place the elements of the array into the appropriate buckets
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / bucket_size;
        buckets[index][count[arr[i]]] = arr[i]; // Place the element in the appropriate bucket
        count[arr[i]]++; // Increment the frequency of the element in the count array
    }

    // Sort the elements in each bucket using any sorting algorithm
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[j] = buckets[i][j];
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}