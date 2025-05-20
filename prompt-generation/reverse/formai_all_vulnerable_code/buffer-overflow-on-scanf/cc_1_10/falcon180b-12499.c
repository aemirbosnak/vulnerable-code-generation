//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

struct element {
    int data;
    int index;
};

void print_array(struct element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

void merge(struct element arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int temp[right - left + 1];

    for (int k = left; k <= right; k++) {
        if (i > mid) {
            temp[k - left] = arr[j++].data;
        }
        else if (j > right) {
            temp[k - left] = arr[i++].data;
        }
        else if (arr[j].data <= arr[i].data) {
            temp[k - left] = arr[j++].data;
        }
        else {
            temp[k - left] = arr[i++].data;
        }
    }

    for (int k = left; k <= right; k++) {
        arr[k].data = temp[k - left];
        arr[k].index = k;
    }
}

void merge_sort(struct element arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    struct element arr[MAX_ELEMENTS];
    int size = 0;

    printf("Enter the elements:\n");
    while (scanf("%d", &arr[size].data) == 1) {
        arr[size].index = size;
        size++;
    }

    merge_sort(arr, 0, size - 1);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}