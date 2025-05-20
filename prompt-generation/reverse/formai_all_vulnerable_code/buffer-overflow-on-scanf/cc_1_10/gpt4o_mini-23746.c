//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print the Fibonacci sequence
void printFibonacci(int n) {
    printf("Fibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Function to calculate factorial
int factorial(int n) {
    if (n < 0) return -1; // Factorial of negative numbers is not defined
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to print factorials
void printFactorials(int n) {
    printf("Factorials from 0 to %d:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }
}

// Function to calculate the sum of an array recursively
int sumArray(int arr[], int size) {
    if (size <= 0) return 0;
    return arr[size - 1] + sumArray(arr, size - 1);
}

// Function to helper to get array input from user
void inputArray(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to print a lovely message
void printLovelyMessage() {
    printf("\n🌟✨ Welcome to the Favorite Math Functions Program! 🌈💖\n");
}

// Main function
int main() {
    printLovelyMessage();

    int fibonacciTerms;
    printf("How many terms of the Fibonacci sequence would you like to see? ");
    scanf("%d", &fibonacciTerms);
    printFibonacci(fibonacciTerms);

    int factorialLimit;
    printf("How many factorials would you like to see? ");
    scanf("%d", &factorialLimit);
    printFactorials(factorialLimit);

    int arraySize;
    printf("How many numbers do you want to sum up? ");
    scanf("%d", &arraySize);
    
    if (arraySize > 0) {
        int *arr = (int *)malloc(arraySize * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        inputArray(arr, arraySize);
        int totalSum = sumArray(arr, arraySize);
        printf("The total sum of the entered numbers is: %d\n", totalSum);
        
        free(arr); // Free the allocated memory
    } else {
        printf("You entered an invalid size for the array!\n");
    }

    // Happy ending message
    printf("\n🎉 Thank you for using the Favorite Math Functions Program! 🌟\n");
    printf("Remember, math is fun! Keep smiling and exploring! 😊💫\n");

    return 0;
}