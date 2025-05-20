//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i; // Product accumulation
    }
    return result; // Return the factorial result
}

// Function to calculate the sum of the first n numbers
int sum_of_n(int n) {
    int sum = 0; // Initialize sum
    for (int i = 1; i <= n; ++i) {
        sum += i; // Summation accumulation
    }
    return sum; // Return the sum result
}

// Function to calculate the Fibonacci sequence up to n terms
void fibonacci(int n) {
    unsigned long long t1 = 0, t2 = 1, nextTerm;
    
    printf("Fibonacci Series: "); // Print header for Fibonacci series
    for (int i = 1; i <= n; ++i) {
        printf("%llu, ", t1); // Display the current term
        nextTerm = t1 + t2; // Compute the next term
        t1 = t2; // Shift terms
        t2 = nextTerm; // Shift terms
    }
    printf("\n"); // New line after series
}

// Main program execution starts here
int main() {
    int n;

    // Prompt user for input
    printf("Enter a positive integer to demonstrate arithmetic operations: ");
    scanf("%d", &n); // Read user input

    // Validate user input
    if (n < 0) {
        printf("The number must be a non-negative integer.\n");
        return 1; // Exit if input is invalid
    }

    // Calculate and display the sum of the first n numbers
    int total_sum = sum_of_n(n);
    printf("The sum of the first %d numbers is: %d\n", n, total_sum);

    // Calculate and display the factorial of the number
    unsigned long long fact_result = factorial(n);
    printf("The factorial of %d is: %llu\n", n, fact_result);

    // Prompt to display Fibonacci sequence
    printf("Enter how many Fibonacci terms you wish to see: ");
    int terms;
    scanf("%d", &terms);

    // Validate Fibonacci terms input
    if (terms < 0) {
        printf("The number must be a non-negative integer.\n");
        return 1; // Exit if input is invalid
    }

    // Display the Fibonacci sequence
    fibonacci(terms);
    
    // Concluding statement
    printf("The magical world of numbers concludes gracefully.\n");

    return 0; // Program completion
}