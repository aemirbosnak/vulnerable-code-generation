//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MIN_VALUE 1
#define MAX_VALUE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    int arr[MAX_SIZE], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

    printf("Unsorted array:\n");
    display(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    display(arr, n);

    return 0;
}