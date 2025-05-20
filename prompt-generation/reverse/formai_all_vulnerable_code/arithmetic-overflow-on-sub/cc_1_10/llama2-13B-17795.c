//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to print a message of gratitude
void print_gratitude(void) {
    printf("Thank you for entrusting me with your list of numbers! I am honored to help you sort them.\n");
}

// Function to sort an array of integers
void sort_array(int arr[], int length) {
    int i, j, min, temp;

    // Print a message of gratitude
    print_gratitude();

    // Check if the length of the array is 0
    if (length == 0) {
        printf("You have given me an empty list. There is nothing to sort.\n");
        return;
    }

    // Loop through the array and find the smallest element
    for (i = 0; i < length - 1; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // If the current element is smaller than the previous smallest element,
        // swap them and update the minimum index
        if (arr[min] < arr[i]) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    // Print the sorted array
    printf("Here is your sorted list of numbers:\n");
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_LENGTH];
    int length;

    // Get the length of the array from the user
    printf("Please enter the length of your list of numbers: ");
    scanf("%d", &length);

    // Get the array elements from the user
    for (int i = 0; i < length; i++) {
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sort_array(arr, length);

    return 0;
}