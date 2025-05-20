//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#define SIZE 10

int main() {
    int arr[SIZE], i, j, min_index, max_index, temp, min_value, max_value;

    printf("Enter %d integers:\n", SIZE);

    // Read integers from user and store in array
    for (i = 0; i < SIZE; i++) {
        printf("Enter integer number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Find minimum and maximum integers using loops
    min_value = arr[0];
    max_value = arr[0];

    for (i = 0; i < SIZE; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        }
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_index = i;
        }
    }

    // Display minimum and maximum integers
    printf("Minimum integer: %d (at index %d)\n", min_value, min_index);
    printf("Maximum integer: %d (at index %d)\n", max_value, max_index);

    // Sort array using Bubble Sort algorithm
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}