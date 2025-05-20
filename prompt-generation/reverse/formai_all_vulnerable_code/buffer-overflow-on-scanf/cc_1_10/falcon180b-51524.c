//Falcon-180B DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>

#define MAX 100

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int l = 0; l < n1; l++)
        L[l] = arr[i++];
    for (int r = 0; r < n2; r++)
        R[r] = arr[j++];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
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

void paranoidMergeSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    if (n == 2) {
        if (arr[0] > arr[1]) {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
    } else {
        int mid = n / 2;

        paranoidMergeSort(arr, mid);
        paranoidMergeSort(arr + mid, n - mid);

        merge(arr, 0, mid - 1, n - 1);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter the elements of the array:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    paranoidMergeSort(arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}