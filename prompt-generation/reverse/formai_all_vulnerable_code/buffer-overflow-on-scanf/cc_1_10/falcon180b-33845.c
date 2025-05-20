//Falcon-180B DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_TRIES 10

void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_NUM;
    }
}

int binarySearch(int arr[], int target, int size) {
    int left = 0;
    int right = size - 1;
    int tries = 0;

    while (left <= right && tries < MAX_TRIES) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        tries++;
    }

    return -1;
}

int main() {
    int arr[MAX_NUM];
    int size, target;

    printf("Enter the size of the array (up to %d): ", MAX_NUM);
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    generateRandomArray(arr, size);

    printf("Array after shuffling:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the target number: ");
    scanf("%d", &target);

    int index = binarySearch(arr, target, size);

    if (index == -1) {
        printf("Target number not found.\n");
    } else {
        printf("Target number found at index %d.\n", index);
    }

    return 0;
}