//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j;
    int bucket[MAX];
    int count[MAX] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i] / 10) % MAX]++;
    }

    for (i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (j = 0; j < count[i]; j++) {
                bucket[j] = i * 10 + 1;
                j++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] / 10) % MAX;
        arr[i] = bucket[count[j]++];
    }
}

int main() {
    int arr[MAX], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}