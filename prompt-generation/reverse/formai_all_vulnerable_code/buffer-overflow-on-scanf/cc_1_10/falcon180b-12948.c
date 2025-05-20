//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

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

void bubbleSort(Element arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int binarySearch(Element arr[], int target, int left, int right) {
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    Element arr[MAX_SIZE];
    int n, i, target, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    bubbleSort(arr, n);

    printf("Enter the target element: ");
    scanf("%d", &target);

    result = binarySearch(arr, target, 0, n - 1);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}