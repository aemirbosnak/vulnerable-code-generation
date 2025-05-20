//Falcon-180B DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

void merge(Node* arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    Node temp[MAX_SIZE];
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
    for (i = left; i <= right; i++) {
        arr[i].data = temp[i].data;
        arr[i].index = temp[i].index;
    }
}

void mergeSort(Node* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    Node arr[MAX_SIZE];
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
    return 0;
}