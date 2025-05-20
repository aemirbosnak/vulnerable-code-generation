//FormAI DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void quickSort(int array[], int left, int right) {
    int i = left, j = right;
    int pivot = array[(left + right) / 2];

    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}

void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void bubbleSort(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int array[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[MAX_SIZE];
    int i, size;
    clock_t t;

    printf("Enter size of array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Size too large!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("\nArray before sorting:\n");
    printArray(array, size);

    t = clock();
    quickSort(array, 0, size - 1);
    t = clock() - t;
    printf("\nArray after Quicksort:\n");
    printArray(array, size);
    printf("QuickSort Time: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    t = clock();
    mergeSort(array, 0, size - 1);
    t = clock() - t;
    printf("\nArray after Mergesort:\n");
    printArray(array, size);
    printf("MergeSort Time: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    t = clock();
    bubbleSort(array, size);
    t = clock() - t;
    printf("\nArray after Bubblesort:\n");
    printArray(array, size);
    printf("BubbleSort Time: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    t = clock();
    insertionSort(array, size);
    t = clock() - t;
    printf("\nArray after Insertionsort:\n");
    printArray(array, size);
    printf("InsertionSort Time: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}