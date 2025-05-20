//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SECRET_KEY 42

// Function to generate a secret array with numbers mixed in a unique pattern
void generateSecretArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) + SECRET_KEY;  // Add SECRET_KEY to mix up numbers
    }
}

// Function to conduct a linear search in search of the hidden treasure
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Found the treasure!
        }
    }
    return -1;  // Treasure not found
}

// Function to conduct a binary search, expecting a sorted array
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;  // Found the treasure!
        }
        if (arr[mid] < key) {
            left = mid + 1;  // Searching in the right half
        } else {
            right = mid - 1;  // Searching in the left half
        }
    }
    return -1;  // Treasure not found
}

// Function to sort the array using Bubble Sort (for binary search)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the treasures
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the treasures in the array
void displayArray(int arr[], int size) {
    printf("Treasures found in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int secretTreasure[MAX];
    int size, key;
    
    // Seed the randomness of the universe 
    srand(time(NULL));
    
    printf("Welcome, treasure hunter! Enter the number of treasures (max 100): ");
    scanf("%d", &size);
    
    // Generate a secret array of treasures
    generateSecretArray(secretTreasure, size);
    displayArray(secretTreasure, size);
    
    printf("Now, enter the secret key you wish to find (e.g., %d): ", SECRET_KEY);
    scanf("%d", &key);

    // Try to find the treasure using linear search
    int linearResult = linearSearch(secretTreasure, size, key);
    if (linearResult != -1) {
        printf("Treasure found at index %d using linear search!\n", linearResult);
    } else {
        printf("Treasure not found using linear search!\n");
    }
    
    // For binary search, we need to sort the treasures
    bubbleSort(secretTreasure, size);
    printf("Treasures have been sorted for a better quest!\n");
    displayArray(secretTreasure, size);

    // Try to find the treasure using binary search
    int binaryResult = binarySearch(secretTreasure, size, key);
    if (binaryResult != -1) {
        printf("Treasure found at index %d using binary search!\n", binaryResult);
    } else {
        printf("Treasure not found using binary search!\n");
    }

    return 0;
}