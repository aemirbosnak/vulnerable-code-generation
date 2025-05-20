//Falcon-180B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid integer
int isInteger(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    char* input = (char*) malloc(100 * sizeof(char));
    int n;

    // Prompt user for input
    printf("Enter a number: ");
    scanf("%s", input);

    // Check if input is a valid integer
    if (!isInteger(input)) {
        printf("Error: Input is not an integer.\n");
        exit(1);
    }

    // Convert input to integer
    n = atoi(input);

    // Calculate factorial and Fibonacci number
    int fact = factorial(n);
    int fib = fibonacci(n);

    // Display results
    printf("Factorial of %d is %d\n", n, fact);
    printf("The %dth Fibonacci number is %d\n", n, fib);

    return 0;
}