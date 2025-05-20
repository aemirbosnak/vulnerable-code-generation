//Falcon-180B DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
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

void countingSort(int arr[], int n) {
    int output[n];
    int count[MAX] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / 2) % MAX]++;

    for (int i = 1; i < MAX; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / 2) % MAX] - 1] = arr[i];
        count[(arr[i] / 2) % MAX]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }

    printf("Sorted array using merge sort:\n");
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    printf("\nSorted array using counting sort:\n");
    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}