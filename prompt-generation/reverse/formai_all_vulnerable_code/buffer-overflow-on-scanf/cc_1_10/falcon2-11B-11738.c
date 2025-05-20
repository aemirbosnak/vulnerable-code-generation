//Falcon2-11B DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(char *arr, int low, int high) {
    if (low < high) {
        int pivot = low;
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (arr[i] < arr[pivot] && i <= j) {
                i++;
            }
            while (arr[j] > arr[pivot] && i <= j) {
                j--;
            }
            if (i <= j) {
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[pivot], &arr[j]);

        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

void printArray(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int main() {
    char arr[100];
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%c", &arr[i]);
    }

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}