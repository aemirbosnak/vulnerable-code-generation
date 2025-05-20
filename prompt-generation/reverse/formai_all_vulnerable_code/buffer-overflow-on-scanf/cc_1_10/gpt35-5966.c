//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// Function to generate a random integer between a given range
int getRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
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

int main() {
    int i, n, arr[MAX_SIZE];
    double time_taken;
    clock_t start, end;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Generate random integers for the array
    for (i = 0; i < n; i++) {
        arr[i] = getRandomNumber(1, 100);
    }

    // Print the unsorted array
    printf("Unsorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Perform Bubble Sort and measure the time taken
    start = clock();
    bubbleSort(arr, n);
    end = clock();

    // Print the sorted array
    printf("\n\nSorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Calculate the time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken by Bubble Sort: %lf seconds\n", time_taken);

    return 0;
}