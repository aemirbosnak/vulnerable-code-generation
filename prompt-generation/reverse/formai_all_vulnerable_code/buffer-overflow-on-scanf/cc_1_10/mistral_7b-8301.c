//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#define MAX_SIZE 50

// Function to print array elements
void printArray(int arr[], int size) {
    int i;
    printf("Elements are:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE], n, i;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input elements of array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call to print initial array
    printArray(arr, n);

    // Function call to sort array using bubble sort
    bubbleSort(arr, n);

    // Function call to print sorted array
    printArray(arr, n);

    return 0;
}