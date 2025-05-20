//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], n;
    char input[MAX_SIZE];

    // Prompt user for array size
    printf("Enter array size (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Prompt user for array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        arr[i] = atoi(input);
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using selection sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}