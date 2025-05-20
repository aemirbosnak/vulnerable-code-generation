//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function declarations
int factorial(int n);
int fibonacci(int n);
void print_array(int *arr, int size);
void reverse_array(int *arr, int start, int end);
void get_user_input(int *n, int *type);

int main() {
    int n, type;
    
    // Get user input for factorial or Fibonacci calculation
    get_user_input(&n, &type);
    
    if (type == 1) {
        // Calculate factorial
        printf("Factorial of %d is: %d\n", n, factorial(n));
    } else if (type == 2) {
        // Calculate Fibonacci number
        printf("%d-th Fibonacci number is: %d\n", n, fibonacci(n));
    } else {
        // Invalid type
        printf("Invalid option selected. Please run the program again.\n");
        return -1;
    }

    // Array reversal example
    int size;
    printf("Enter the size of array to be reversed: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    print_array(arr, size);
    
    // Reverse the array recursively
    reverse_array(arr, 0, size - 1);
    
    printf("Reversed array: ");
    print_array(arr, size);
    
    // Free dynamically allocated memory
    free(arr);
    
    return 0;
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial not defined for negative numbers
    }
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate Fibonacci recursively
int fibonacci(int n) {
    if (n < 0) {
        return -1; // Fibonacci not defined for negative numbers
    }
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print an array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to reverse an array recursively
void reverse_array(int *arr, int start, int end) {
    if (start >= end) {
        return; // Base case
    }

    // Swap the elements
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive call
    reverse_array(arr, start + 1, end - 1);
}

// Function to get user input for the type of calculation
void get_user_input(int *n, int *type) {
    printf("Enter a non-negative integer: ");
    scanf("%d", n);
    printf("Choose the operation:\n");
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    printf("Your choice: ");
    scanf("%d", type);
}