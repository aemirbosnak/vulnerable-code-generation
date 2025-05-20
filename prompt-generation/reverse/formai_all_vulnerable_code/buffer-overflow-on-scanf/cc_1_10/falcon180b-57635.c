//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, k, max = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int *buckets = malloc(sizeof(int) * max + 1);
    for (i = 0; i <= max; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < n; i++) {
        j = arr[i] / (MAX_SIZE / max);
        k = buckets[j]++;
        while (k > 0 && arr[k - 1] > arr[i]) {
            arr[k] = arr[k - 1];
            k--;
        }
        arr[k] = arr[i];
    }
    free(buckets);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        swap(&arr[i], &arr[rand() % n]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}