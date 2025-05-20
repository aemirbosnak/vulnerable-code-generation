//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void shuffle(int arr[], int n) {
    srand(time(0));
    int i;
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        swap(&arr[i], &arr[j]);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE], i, n, choice, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the choice of encryption:\n1. Shuffle\n2. Selection Sort\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            shuffle(arr, n);
            printf("Shuffled array: ");
            printArray(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            printf("Sorted array: ");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}