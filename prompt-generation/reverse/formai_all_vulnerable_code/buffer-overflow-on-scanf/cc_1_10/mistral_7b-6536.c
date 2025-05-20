//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
int isEmpty(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (isEmpty(arr, size)) {
        printf("Error! Array cannot be empty.\n");
        return -1;
    }

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted array:\n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int isEmpty(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] != 0) {
            return 0;
        }
    }

    return 1;
}