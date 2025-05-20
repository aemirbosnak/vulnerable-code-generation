//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Alan Turing
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    // Bubble Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // To optimize, we check if a swap happened
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

void printArray(int arr[], int n) {
    // Function to print the elements of the array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Prompt user to enter the number of elements
    printf("Welcome to the Bubble Sort Program!\n");
    printf("How many elements do you want to sort? ");
    scanf("%d", &n);

    // Allocate an array of size n
    int arr[n];

    // Asking user to input the array elements
    printf("Please enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Displaying the original array
    printf("Original array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array
    bubbleSort(arr, n);

    // Printing the sorted array
    printArray(arr, n);

    return 0;
}