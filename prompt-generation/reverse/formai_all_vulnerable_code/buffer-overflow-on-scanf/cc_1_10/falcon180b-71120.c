//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to generate random integers
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate an array of random integers
void generateArray(int arr[], int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = randInt(1, MAX);
    }
}

int main() {
    int arr[MAX];
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    generateArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}