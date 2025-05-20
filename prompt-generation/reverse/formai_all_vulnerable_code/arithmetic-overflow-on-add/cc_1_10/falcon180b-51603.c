//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int range = max / n;
    int *buckets = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int k = arr[i] / range;
        buckets[k]++;
    }
    for (int i = 1; i < n; i++) {
        buckets[i] += buckets[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < buckets[i]; j++) {
            int k = j * range + i * range;
            swap(&arr[k], &arr[k+range]);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}