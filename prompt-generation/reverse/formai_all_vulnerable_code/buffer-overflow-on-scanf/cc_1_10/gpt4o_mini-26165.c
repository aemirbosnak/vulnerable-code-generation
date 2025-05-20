//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bubble sort with a twist
void quirkyBubbleSort(int arr[], int n, int quirkiness) {
    int i, j, temp;
    int isSwapped;

    for (i = 0; i < n - 1; i++) {
        isSwapped = 0;

        // The quirkiness factor changes the comparison operation
        for (j = 0; j < n - i - 1; j++) {
            if ((arr[j] + quirkiness) > (arr[j + 1] + quirkiness)) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = 1;
            }
        }

        // If no two elements were swapped in the inner loop, break
        if (!isSwapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate a random array of integers
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Main function
int main() {
    int size, quirkiness;

    // Seed for randomness
    srand(time(NULL));

    // User input for size of the array
    printf("Welcome to the Quirky Bubble Sort Program!\n");
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &size);

    int arr[size];

    // Generate random array
    generateRandomArray(arr, size);
    printf("Original array: ");
    printArray(arr, size);

    // User input for quirkiness factor
    printf("Enter a quirkiness factor (an integer): ");
    scanf("%d", &quirkiness);

    // Perform quirky bubble sort
    quirkyBubbleSort(arr, size, quirkiness);
    printf("Sorted array with quirkiness factor %d: ", quirkiness);
    printArray(arr, size);

    return 0;
}