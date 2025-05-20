//Falcon-180B DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void bubbleSort(Element arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].data > arr[j + 1].data) {
                // Swap the elements
                temp = arr[j].data;
                arr[j].data = arr[j + 1].data;
                arr[j + 1].data = temp;

                // Update the indices
                arr[j].index = j;
                arr[j + 1].index = j + 1;
            }
        }
    }
}

void printArray(Element arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d (%d)\n", arr[i].data, arr[i].index);
    }
}

int main() {
    Element arr[MAX_SIZE];
    int n, i;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // Perform the bubble sort
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}