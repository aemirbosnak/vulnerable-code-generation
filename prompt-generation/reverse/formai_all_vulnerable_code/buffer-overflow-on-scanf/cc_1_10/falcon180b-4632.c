//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int low, int high) {
    Element pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(Element arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    Element arr[MAX_SIZE];
    int n, i, target;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }

    printf("\n");

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}