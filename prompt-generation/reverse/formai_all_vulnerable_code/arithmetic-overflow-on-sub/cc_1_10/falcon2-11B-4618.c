//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number within a range
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to search for a target element in an array
int search_array(int *arr, int n, int target) {
    int low = 0, high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to generate a random array of integers
int *generate_random_array(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand_range(1, 100);
    }
    return arr;
}

// Main function
int main() {
    int n, target, *arr, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = generate_random_array(n);
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the target element: ");
    scanf("%d", &target);

    int index = search_array(arr, n, target);

    if (index!= -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}