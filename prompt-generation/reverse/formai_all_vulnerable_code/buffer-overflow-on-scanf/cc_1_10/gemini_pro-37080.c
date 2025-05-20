//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Knuth's MIX assembler syntax
#define LDA 0x01
#define ADD 0x18
#define STA 0x03
#define JMP 0x4C
#define JEQ 0x45
#define JGT 0x4A
#define JLT 0x4D
#define JNE 0x49
#define OUT 0x08
#define HLT 0x61

// Data segment
#define DATA_START 0x1000
#define ARRAY_START 0x1100
#define ARRAY_SIZE 10

// Code segment
#define CODE_START 0x2000
#define MAIN_ROUTINE 0x2100

// Constants
#define TRUE 1
#define FALSE 0

// Prototypes
int linear_search(int arr[], int size, int target);

// Main routine
int main() {
    // Initialize the array
    int arr[ARRAY_SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Print the array
    printf("Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get the target value
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Perform the linear search
    int result = linear_search(arr, ARRAY_SIZE, target);

    // Print the result
    if (result == -1) {
        printf("Target value not found.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    return 0;
}

// Linear search function
int linear_search(int arr[], int size, int target) {
    // Initialize the index
    int index = 0;

    // Loop through the array
    while (index < size) {
        // Compare the target value to the current element
        if (arr[index] == target) {
            // Target value found, return the index
            return index;
        } else {
            // Target value not found, increment the index
            index++;
        }
    }

    // Target value not found, return -1
    return -1;
}