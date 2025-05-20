//Falcon-180B DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void swap(Element arr[], int i, int j) {
    Element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(Element arr[], int n) {
    int i;
    for (i = 1; i < n; i++) {
        Element key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].data > key.data) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(Element arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Element L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].data <= R[j].data) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Element arr[], int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Element arr[MAX_SIZE];
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    insertionSort(arr, n);
    printf("Sorted array using Insertion Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].data);

    mergeSort(arr, 0, n - 1);
    printf("\nSorted array using Merge Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].data);

    return 0;
}