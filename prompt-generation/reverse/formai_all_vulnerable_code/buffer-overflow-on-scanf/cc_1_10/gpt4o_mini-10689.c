//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then the array is sorted
        if (!swapped)
            break;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("🔍 Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to add numbers to the array
int addNumbers(int arr[], int size) {
    int num;
    printf("📥 Enter a number to add to the array (or -1 to stop): ");
    while (true) {
        scanf("%d", &num);
        if (num == -1) break;
        arr[size] = num;
        size++;
        printf("✅ Added %d to the array! 📈\n", num);
        printArray(arr, size);
        printf("📥 Enter another number (or -1 to stop): ");
    }
    return size;
}

int main() {
    int arr[100];
    int size = 0;
    char choice;

    printf("🎉 Welcome to the Super Sorting Simulator! 🎉\n");
    
    // Add numbers to the array
    size = addNumbers(arr, size);

    // Show current numbers before sorting
    printArray(arr, size);
    
    // Ask user if they want to sort
    printf("🧐 Do you want to sort the array? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("🚀 Sorting the array using Bubble Sort...\n");
        bubbleSort(arr, size);
        printf("✨ Array sorted successfully! 🎉\n");
        printArray(arr, size);
    } else {
        printf("😎 Keeping the array as is, maybe next time!\n");
    }
    
    printf("👋 Thank you for playing with the Super Sorting Simulator! Bye!\n");
    return 0;
}