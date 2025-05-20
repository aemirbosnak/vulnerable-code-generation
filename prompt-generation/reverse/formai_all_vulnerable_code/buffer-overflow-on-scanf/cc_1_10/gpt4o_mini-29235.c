//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) {
    printf("Current array state: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Choosing the last element as pivot
    int i = (low - 1);        // Index of smaller element

    printf("The brave hero chooses %d as the pivot...\n", pivot);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;    // Increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printf("The hero exchanges %d with %d!\n", arr[i], arr[j]);
            printArray(arr, high - low + 1);  // Show the current state of the array
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    printf("The hero finally places %d in its rightful place!\n", arr[i + 1]);
    printArray(arr, high - low + 1);

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        printf("As the hero continues, the journey splits at %d...\n\n", pi);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Welcome to the Sorting Adventure!\n");
    printf("How many integers do you want to sort today? ");
    scanf("%d", &n);

    // Seed the random number generator and create an array
    srand(time(NULL));
    int *arr = (int *)malloc(n * sizeof(int));

    printf("You shall encounter the following numbers:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0-99
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Now, our hero begins the quest to sort these numbers...\n\n");
    quickSort(arr, 0, n - 1);

    printf("Victory! The sorted numbers are:\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    free(arr); // Clean up the allocated memory
    return 0;
}