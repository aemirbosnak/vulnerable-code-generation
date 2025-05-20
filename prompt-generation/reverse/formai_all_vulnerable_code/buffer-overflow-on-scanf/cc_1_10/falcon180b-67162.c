//Falcon-180B DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Entry;

void swap(Entry* a, Entry* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    temp = a->index;
    a->index = b->index;
    b->index = temp;
}

int compare(const void* a, const void* b) {
    Entry* entryA = (Entry*)a;
    Entry* entryB = (Entry*)b;
    if (entryA->data < entryB->data) {
        return -1;
    } else if (entryA->data > entryB->data) {
        return 1;
    } else {
        return 0;
    }
}

void merge(Entry* arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    Entry temp[MAX_SIZE];
    while (i <= mid && j <= right) {
        if (arr[i].data <= arr[j].data) {
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
    for (int l = left; l <= right; l++) {
        arr[l] = temp[l - left];
    }
}

void mergeSort(Entry* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    Entry arr[MAX_SIZE];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
    return 0;
}