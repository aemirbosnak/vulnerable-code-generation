//Falcon-180B DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>

#define MAX_SIZE 100

/* Function to swap two elements */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to implement selection sort */
void selectionSort(int arr[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;

    /* Get the size of the array from the user */
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &n);

    /* Get the elements of the array from the user */
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Sort the array using selection sort */
    selectionSort(arr, n);

    /* Print the sorted array */
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}