//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Welcome to the Ultimate Shockingly Simple Sorting Program!\n");
    printf("Oh wow, are you ready to sort some numbers? I hope so!\n");

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Whoa! That's not a valid number of elements! Exiting...\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Oh no! Memory allocation failed! Exiting...\n");
        return 1;
    }

    printf("Please, enter %d numbers to sort:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Your original array is: ");
    printArray(arr, n);

    printf("Sorting the numbers using bubble sort... Hold on tight!\n");
    bubbleSort(arr, n);
    printf("Surprise! The sorted array is: ");
    printArray(arr, n);

    free(arr);
    printf("Memory has been freed, and we are all set! Bye!\n");
    return 0;
}