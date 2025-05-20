//Falcon-180B DATASET v1.0 Category: Recursive ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

int arr[MAX];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quicksort(low, j);
    if (i < high)
        quicksort(i, high);
}

void printarray(int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i, n;
    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(0, n - 1);
    printf("Sorted array:\n");
    printarray(n);

    return 0;
}