//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int main() {
    int i, j, n;
    int *arr1, *arr2;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr1 = (int *)malloc(n * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        arr1[i] = rand() % MAX_SIZE;
    }

    printf("\nOriginal array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    for (i = 0; i < n; i++) {
        arr2[i] = rand() % MAX_SIZE;
    }

    printf("\nSecond array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr2[j] > arr2[j + 1]) {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    printf("\nSorted second array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);

    return 0;
}