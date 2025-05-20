//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo's sorting function
void romeoSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Juliet's sorting function
void julietSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Romeo's sorting function
    romeoSort(arr, n);
    printf("After Romeo's sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Juliet's sorting function
    julietSort(arr, n);
    printf("\nAfter Juliet's sorting: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}