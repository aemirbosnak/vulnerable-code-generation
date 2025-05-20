//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function prototypes
void selectionSort(int arr[], int n);
void displayArray(int arr[], int n);
void populateArray(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int size;
    
    printf("🎉 Welcome to the Array Surprise Sorter! 🎉\n");
    printf("How many elements would you like to sort (max %d)? ", MAX_SIZE);
    
    while (1) {
        scanf("%d", &size);
        if (size > 0 && size <= MAX_SIZE) {
            break;
        } else {
            printf("Oops! Please enter a valid number between 1 and %d: ", MAX_SIZE);
        }
    }
    
    populateArray(arr, size);
    
    printf("🌀 Original Array: ");
    displayArray(arr, size);
    
    selectionSort(arr, size);
    
    printf("✨ Sorted Array: ");
    displayArray(arr, size);
    
    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Surprise: Show the current state of the array!
        printf("🔄 Step %d: ", i + 1);
        displayArray(arr, n);
    }
}

void populateArray(int arr[], int n) {
    srand(time(NULL)); // Seed the random number generator
    printf("🌟 Populating the array with random numbers...\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}