//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void shuffleArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int binarySearch(int arr[], int target, int low, int high) {
    if (low > high) {
        printf("Element not found in array.\n");
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        printf("Element found at index %d.\n", mid);
        return mid;
    }

    if (arr[mid] > target) {
        return binarySearch(arr, target, low, mid - 1);
    } else {
        return binarySearch(arr, target, mid + 1, high);
    }
}

int main() {
    int target;

    printf("Enter the element you want to search for: ");
    scanf("%d", &target);

    shuffleArray(arr, SIZE);

    int index = binarySearch(arr, target, 0, SIZE - 1);

    if (index!= -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found in array.\n");
    }

    return 0;
}