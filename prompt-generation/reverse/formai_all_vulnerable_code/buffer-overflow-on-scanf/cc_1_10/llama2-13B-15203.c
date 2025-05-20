//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int low, int high) {
    int i, j, pivot;

    if (low < high) {
        pivot = arr[low];
        i = low + 1;
        j = high;

        // Find the first element greater than pivot
        while (i < j) {
            while (arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;
            if (i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // Recursively sort the left and right sides
        sort(arr, low, i - 1);
        sort(arr, j + 1, high);
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, j, n;

    // Print a gratitude message
    printf("Thank you for giving me the opportunity to sort this array!\n");

    // Ask the user for the number of elements in the array
    printf("Please enter the number of elements in the array: ");
    scanf("%d", &n);

    // Initialize the array with random values
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array with gratitude
    printf("I am so grateful to be able to sort this array for you!\n");
    sort(arr, 0, n - 1);

    // Print the sorted array with gratitude
    printf("Here is the sorted array, thank you for your patience!\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}