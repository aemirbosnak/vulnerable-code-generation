//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate Fibonacci number recursively
int fibonacci(int n) {
    // Base case: the first two Fibonacci numbers
    if (n == 0) {
        printf("fibonacci(0) = 0\n");
        return 0;
    } 
    else if (n == 1) {
        printf("fibonacci(1) = 1\n");
        return 1;
    } 
    // Recursive case
    else {
        printf("Calculating fibonacci(%d)\n", n);
        int result = fibonacci(n - 1) + fibonacci(n - 2);
        printf("fibonacci(%d) = %d\n", n, result);
        return result;
    }
}

// Function to display Fibonacci series up to n terms
void displayFibonacciSeries(int n) {
    printf("Fibonacci series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Main function
int main() {
    int number;

    // Welcome message
    printf("Welcome to the Fibonacci Calculator!\n");
    printf("Please enter a positive integer to calculate Fibonacci series: ");
    
    // Input validation loop
    while (1) {
        scanf("%d", &number);
        
        if (number >= 0) {
            break; // Valid input, exit the loop
        } else {
            printf("Please enter a positive integer (0 or greater): ");
        }
    }

    // Display the Fibonacci series
    displayFibonacciSeries(number);

    // Exit message
    printf("Thank you for using the Fibonacci Calculator!\n");
    return 0;
}