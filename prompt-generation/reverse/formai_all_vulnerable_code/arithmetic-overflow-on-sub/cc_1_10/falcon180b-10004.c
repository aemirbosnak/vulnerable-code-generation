//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(1, MAX_SIZE);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    srand(time(NULL));

    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    generateRandomArray(arr, size);
    printArray(arr, size);

    printf("\nEnter the target number to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result == -1) {
        printf("\n%d not found in the array.\n", target);
    } else {
        printf("\n%d found at position %d.\n", target, result);
    }

    return 0;
}