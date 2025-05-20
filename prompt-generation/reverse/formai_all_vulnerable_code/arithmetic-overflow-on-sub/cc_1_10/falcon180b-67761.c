//Falcon-180B DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 1000

int compare(const void* a, const void* b) {
    int* ia = (int*)a;
    int* ib = (int*)b;
    return *ia - *ib;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int temp[MAX_ELEMENTS];

    i = left;
    j = mid + 1;
    k = 0;

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

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[MAX_ELEMENTS];
    int n;
    int i;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}