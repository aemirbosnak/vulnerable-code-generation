//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int value;
    int index;
} pair;

pair create_pair(int value, int index) {
    pair p;
    p.value = value;
    p.index = index;
    return p;
}

int compare_pairs(const void *a, const void *b) {
    pair *p1 = (pair *) a;
    pair *p2 = (pair *) b;
    return (*p1).value - (*p2).value;
}

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int l = 0; l < n1; l++)
        L[l] = arr[left + l];
    for (int r = 0; r < n2; r++)
        R[r] = arr[mid + 1 + r];

    i = 0;
    j = 0;
    k = left;

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

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int binary_search(int arr[], int target, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            return binary_search(arr, target, left, mid - 1);
        else
            return binary_search(arr, target, mid + 1, right);
    }

    return -1;
}

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare_pairs);

    printf("Enter target value: ");
    scanf("%d", &target);

    int result = binary_search(arr, target, 0, n - 1);

    if (result == -1)
        printf("Target value not found!\n");
    else
        printf("Target value found at index %d.\n", result);

    return 0;
}