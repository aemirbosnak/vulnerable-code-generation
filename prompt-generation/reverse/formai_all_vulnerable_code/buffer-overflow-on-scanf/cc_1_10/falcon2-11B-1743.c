//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    srand(time(NULL)); // seed random number generator
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr1[n], arr2[n];

    printf("Enter the elements of array 1:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of array 2:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    // sort array 1
    bubbleSort(arr1, n);
    printf("Array 1 after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    // sort array 2
    bubbleSort(arr2, n);
    printf("\nArray 2 after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}