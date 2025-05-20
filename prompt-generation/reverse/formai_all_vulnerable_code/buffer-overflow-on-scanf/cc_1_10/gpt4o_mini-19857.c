//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function implementing a curious version of Binary Search
int curiousBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    printf("Welcome to the Binary Search Adventure!\n");
    printf("We are searching for %d in an enchanted array.\n", target);

    while (left <= right) {
        printf("The mystical boundary is from %d to %d.\n", left, right);
        int mid = left + (right - left) / 2;
        printf("The magic point of conjecture lies at index %d (value: %d).\n", mid, arr[mid]);

        if (arr[mid] == target) {
            printf("Eureka! We have found the mystical number %d at index %d!\n", target, mid);
            return mid; // Found
        }

        if (arr[mid] < target) {
            printf("The number is greater! Searching to the right...\n");
            left = mid + 1;
        } else {
            printf("The number is smaller! Searching to the left...\n");
            right = mid - 1;
        }
    }

    printf("Alas! The number %d dwells in the shadows of the unknown!\n", target);
    return -1; // Not found
}

// Function to print an array
void printArray(int arr[], int size) {
    printf("The enchanted array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to orchestrate the search
int main() {
    int arr[] = {12, 3, 5, 1, 7, 9, 8, 4, 11, 6, 10, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Step right up for an array quest! Let’s sort the array first...\n");
    qsort(arr, size, sizeof(int), compareInts);
    printArray(arr, size);

    // The target to search for
    int target;
    printf("What magical number do you seek? ");
    scanf("%d", &target);

    // Invoke the curious search
    curiousBinarySearch(arr, size, target);
    
    return 0;
}