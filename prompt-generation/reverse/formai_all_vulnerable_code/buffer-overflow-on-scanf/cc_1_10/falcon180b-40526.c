//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Fill the array with random values
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Search for a value in the array
    int search_val;
    printf("Enter the value to search for: ");
    scanf("%d", &search_val);

    int index = linear_search(arr, size, search_val);
    if (index == -1) {
        printf("Value not found in the array.\n");
    } else {
        printf("Value found at index %d.\n", index);
    }

    return 0;
}

int linear_search(int arr[], int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}