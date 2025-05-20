//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MIN_VALUE -100
#define ARRAY_SIZE 25

// Function to generate a random array
void generate_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_SIZE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an integer value within an array using the C searching algorithm with a twist
int search_array(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        // The twist: if the middle element is the target, print the indices of the left and right neighbors
        if (arr[mid] == target) {
            if (mid > 0 && arr[mid - 1] != target) {
                printf("Found at indices %d and %d.\n", mid - 1, mid);
                return mid;
            }
            if (mid < size - 1 && arr[mid + 1] != target) {
                printf("Found at indices %d and %d.\n", mid, mid + 1);
                return mid;
            }
        }
        // Standard binary search logic
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Target not found
    return -1;
}

int main() {
    int arr[ARRAY_SIZE], target;
    generate_array(arr, ARRAY_SIZE);
    print_array(arr, ARRAY_SIZE);
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    search_array(arr, ARRAY_SIZE, target);
    return 0;
}