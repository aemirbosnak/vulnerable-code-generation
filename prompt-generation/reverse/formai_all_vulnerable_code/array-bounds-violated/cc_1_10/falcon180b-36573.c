//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

int data[SIZE];

void init(int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100;
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = data[(left + right) / 2];

    do {
        while (data[i] > pivot)
            i++;
        while (data[j] < pivot)
            j--;
        if (i <= j) {
            swap(&data[i], &data[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        quicksort(left, j);
    if (i < right)
        quicksort(i, right);
}

void printarray(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    init(n);
    quicksort(0, n - 1);
    printarray(n);
    return 0;
}