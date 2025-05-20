//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <limits.h>
#include <string.h>

// Helper function to swap two numbers
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to count the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num!= 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to sort an array using Radix Sort
void radixSort(int arr[], int n) {
    int max_digit = 0;

    // Find the maximum number and its digits
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_digit) {
            max_digit = arr[i];
        }
    }

    // Loop through each digit of the maximum number
    for (int i = 0; max_digit /= 10; i++) {
        int digits[10];

        // Count the number of digits for the current digit
        int count = countDigits(max_digit % 10);

        // Initialize the array of digits
        memset(digits, 0, sizeof(digits));

        // Count the number of occurrences of each digit
        for (int j = 0; j < n; j++) {
            int digit = arr[j] / (max_digit / 10) % 10;
            digits[digit]++;
        }

        // Sort the array of digits
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k < count - 1; k++) {
                if (digits[j] > digits[k]) {
                    swap(&digits[j], &digits[k]);
                }
            }
        }

        // Place the sorted digits back into the array
        for (int j = 0; j < n; j++) {
            arr[j] /= (max_digit / 10) % 10;
            arr[j] += digits[arr[j] % 10];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {123, 45, 67, 89, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using Radix Sort
    radixSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}