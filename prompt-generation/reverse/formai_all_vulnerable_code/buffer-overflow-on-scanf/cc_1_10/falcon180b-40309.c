//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateArray(int arr[], int size);
int binarySearch(int arr[], int size, int target);
double getExecutionTime(clock_t start, clock_t end);

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    generateArray(arr, size);
    printf("Enter the target value to search for: ");
    scanf("%d", &target);
    int result = binarySearch(arr, size, target);
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }
    return 0;
}

void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int binarySearch(int arr[], int size, int target) {
    clock_t start = clock();
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    clock_t end = clock();
    double executionTime = getExecutionTime(start, end);
    printf("Binary search completed in %.4f seconds.\n", executionTime);
    return -1;
}

double getExecutionTime(clock_t start, clock_t end) {
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
    return timeSpent;
}