//Falcon-180B DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[MAX_SIZE];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arrSize;
    int arr[MAX_SIZE];

    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    int i;
    for (i = 0; i < arrSize; i++) {
        arr[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("After sorting:\n");
    printArray(arr, arrSize);

    return 0;
}