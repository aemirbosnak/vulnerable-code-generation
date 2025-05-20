//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
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

int binarySearch(Element arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;
    Element arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    bubbleSort(arr, n);

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}