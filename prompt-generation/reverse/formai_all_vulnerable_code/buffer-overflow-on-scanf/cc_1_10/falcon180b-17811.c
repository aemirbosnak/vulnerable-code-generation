//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void bucketSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int i, n;
    int arr[SIZE];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: \n");
    printArray(arr, n);

    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[10] = {0};
    int count[10] = {0};

    max = arr[0];
    min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / 10;

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] - min) / bucketSize;
        count[j]--;
        arr[count[j]] = arr[i];
    }
}

void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}