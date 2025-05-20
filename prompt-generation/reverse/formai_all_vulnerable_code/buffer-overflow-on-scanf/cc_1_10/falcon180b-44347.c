//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, bucket[MAX];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    range = max - min + 1;
    for (i = 0; i < range; i++)
        bucket[i] = 0;
    for (i = 0; i < n; i++)
        bucket[arr[i] - min]++;
    for (i = 0; i < n; i++) {
        for (j = bucket[arr[i] - min] - 1; j >= 0; j--) {
            arr[i + j * range] = arr[i];
            arr[i] = 0;
        }
        bucket[arr[i] - min] = 0;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i, n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    srand(time(NULL));
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Unsorted array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    free(arr);
    return 0;
}