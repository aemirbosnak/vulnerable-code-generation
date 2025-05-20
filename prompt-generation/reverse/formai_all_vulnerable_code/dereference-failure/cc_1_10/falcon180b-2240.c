//Falcon-180B DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000000
#define MAX_K 100

typedef struct {
    int *a;
    int n;
} IntArray;

void quicksort(IntArray arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr.a[(left + right) / 2];

    while (i <= j) {
        while (arr.a[i] < pivot)
            i++;
        while (arr.a[j] > pivot)
            j--;
        if (i <= j) {
            int temp = arr.a[i];
            arr.a[i] = arr.a[j];
            arr.a[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void printarray(IntArray arr) {
    int n = arr.n;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr.a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int n = rand() % MAX_N + 1;
    int k = rand() % MAX_K + 1;

    IntArray array;
    array.a = (int *)malloc(n * sizeof(int));
    array.n = n;

    for (int i = 0; i < n; i++) {
        array.a[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    printarray(array);

    quicksort(array, 0, n - 1);

    printf("After sorting:\n");
    printarray(array);

    int kth = array.a[k - 1];

    printf("The %dth smallest element is %d.\n", k, kth);

    free(array.a);
    return 0;
}