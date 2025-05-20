//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

int get_bucket_index(int value) {
    return value / 10;
}

void bucket_sort(int arr[], int size) {
    int i, j, k, temp;
    int bucket[MAX_SIZE];

    // Initialize bucket array with 0
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = 0;
    }

    // Place elements in buckets
    for (i = 0; i < size; i++) {
        int index = get_bucket_index(arr[i]);
        bucket[index]++;
    }

    // Modify the elements in the array to have the correct position
    for (i = 0, j = 0; i < MAX_SIZE; i++) {
        for (k = 0; k < bucket[i]; k++) {
            arr[j] = i * 10;
            j++;
        }
    }

    // Sort the elements in the array
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE], size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get array elements from user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucket_sort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}