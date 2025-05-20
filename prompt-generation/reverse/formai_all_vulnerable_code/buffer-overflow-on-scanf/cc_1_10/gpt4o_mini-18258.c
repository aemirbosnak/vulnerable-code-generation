//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size;

    // Seed the random number generator for some zesty random values!
    srand(time(0));

    printf("🎉 Welcome to the Ultimate Array Sorting Adventure! 🎉\n");
    printf("Enter the number of elements in your array (1 to %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Ensure valid size
    if (size < 1 || size > MAX_SIZE) {
        printf("🌟 Oops! The size must be between 1 and %d. Let's try it again! 🌟\n", MAX_SIZE);
        return 1;
    }

    // Generate an array of random integers
    printf("🌈 Here's your randomly generated array: \n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random integers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Let's get groovy with sorting!
    printf("🎶 Now we're going to sort your array using Bubble Sort! 🎶\n");
    bubbleSort(arr, size);

    // Show the sorted array
    printf("🏆 Woohoo! Your sorted array is: \n");
    printArray(arr, size);

    return 0;
}

// Function to perform bubble sort on the array
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            // Compare and swap if needed
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                printf("✨ Swapped %d and %d! 🌟\n", arr[j + 1], arr[j]);
            }
        }

        // If no elements were swapped, break the loop early
        if (!swapped) {
            printf("🎉 No more swaps needed, array is sorted! 🎉\n");
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