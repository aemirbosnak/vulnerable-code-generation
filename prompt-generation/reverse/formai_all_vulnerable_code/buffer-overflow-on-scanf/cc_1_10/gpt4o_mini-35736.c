//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate Fibonacci recursively
unsigned long long fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to fill an array with Fibonacci numbers up to n
void fillFibonacciArray(int n, unsigned long long *fibArray) {
    for (int i = 0; i < n; i++) {
        fibArray[i] = fibonacci(i);
    }
}

// Function to print the Fibonacci series
void printFibonacciSeries(unsigned long long *fibArray, int n) {
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%llu ", fibArray[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Get user input
    printf("Enter the number of terms in Fibonacci series (0 to quit): ");
    while (scanf("%d", &n) == 1 && n >= 0) {
        if (n > 93) { // to prevent overflow for unsigned long long
            printf("Please enter a number less than or equal to 93.\n");
        } else {
            unsigned long long *fibArray = (unsigned long long *)malloc(n * sizeof(unsigned long long));
            if (fibArray == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }

            // Fill the Fibonacci array
            fillFibonacciArray(n, fibArray);

            // Print the Fibonacci series
            printFibonacciSeries(fibArray, n);

            // Free allocated memory
            free(fibArray);
        }
        printf("Enter the number of terms in Fibonacci series (0 to quit): ");
    }

    printf("Program terminated.\n");
    return 0;
}