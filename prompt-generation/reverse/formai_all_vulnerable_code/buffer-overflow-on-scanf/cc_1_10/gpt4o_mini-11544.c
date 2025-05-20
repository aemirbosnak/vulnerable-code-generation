//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n-1; i++) {
        swapped = 0; // Flag to check if a swap happened
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        // If no swap happened, the array is already sorted
        if (swapped == 0)
            break;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("Sorted Array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int n;

    // Introduction to the program
    printf("Welcome to the Super Sorting Adventure! 🎉\n");
    printf("How many numbers would you like to sort? (max 100): ");
    scanf("%d", &n);
    
    // Check if numbers are within the acceptable range
    if(n <= 0 || n > 100) {
        printf("Oops! That's out of range. Please start over with a valid number! 🚫\n");
        return 1; // Exit the program with error
    }

    int arr[n]; // Declare array of size n

    // Input numbers from user
    printf("Awesome! Please enter %d integers to sort them: \n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // Display the array before sorting
    printf("You entered: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");

    // Sorting the array
    printf("Let's sort those numbers! 🚀\n");
    bubbleSort(arr, n);

    // Print the sorted array
    printArray(arr, n);
    
    // Celebration of sorting completion
    printf("Yay! The sorting is complete! 🎊\n");
    printf("Thank you for joining the Super Sorting Adventure! Until next time! 🌟\n");
    
    return 0; // End of program
}