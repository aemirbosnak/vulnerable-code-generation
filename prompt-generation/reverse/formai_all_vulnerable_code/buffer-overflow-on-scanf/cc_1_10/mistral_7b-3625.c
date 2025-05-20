//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print array elements with some humor
void print_elements(int *arr, int size) {
    printf("Elements in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, arr[i]);
    }
    printf("\nMmmm, I can smell the magic numbers!\n");
}

// CinnamonSearChi: Modified Binary Search Algorithm with a Cinnamon Twist
int CinnamonSearChi(int *arr, int size, int target) {
    int low = 0, high = size - 1, mid;

    // Simulating the brewing process of Cinnamon tea
    printf("\nBrewing some Cinnamon tea for the search...\n");
    sleep(3); // Simulate brewing time

    while (low <= high) {
        mid = (low + high) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            printf("Search completed! Found %d at index %d.\n", target, mid);
            return mid;
        }

        // If target greater, ignore left half
        if (arr[mid] < target) {
            low = mid + 1;
            printf("Target is on the right side, continuing search...\n");
        }

        // If target is smaller, ignore right half
        else {
            high = mid - 1;
            printf("Target is on the left side, continuing search...\n");
        }
    }

    // Target is not present in array
    printf("Search completed! %d not found in the array.\n", target);
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the value to search for: ");
    scanf("%d", &target);

    print_elements(arr, size);

    CinnamonSearChi(arr, size, target);

    return 0;
}