//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, max, min, temp, index;
    int bucket[MAX_SIZE];

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] *= -1;
        }
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        index = (arr[i] - min) * (MAX_SIZE - 1) / (max - min);
        bucket[index]++;
    }

    for (i = 0; i < n; i++) {
        index = (arr[i] - min) * (MAX_SIZE - 1) / (max - min);
        for (j = 0; j < bucket[index]; j++) {
            if (arr[j] == arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        bucket[index]++;
    }
}

int main() {
    int arr[] = { -1, 3, 5, -2, 7, -6, 8, -4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}