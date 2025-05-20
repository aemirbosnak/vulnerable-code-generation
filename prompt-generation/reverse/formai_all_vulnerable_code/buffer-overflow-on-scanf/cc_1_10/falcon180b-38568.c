//Falcon-180B DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int arr[MAX_SIZE];

void generateArray(int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i-1] > arr[i]) {
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generateArray(size);
    printf("Unsorted array:\n");
    printArray(size);

    bubbleSort(size);
    printf("Sorted array:\n");
    printArray(size);

    return 0;
}