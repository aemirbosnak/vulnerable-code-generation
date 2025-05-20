//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void printFibonacci(int n);
int fibonacci(int n);

int main() {
    int number;
    char input[10];

    printf("Welcome to the Fibonacci Sequence Generator!\n");
    
    while (1) {
        printf("Enter the number of terms you want to generate (1-30): ");
        fgets(input, sizeof(input), stdin);        // Read input

        // Convert input to integer
        number = atoi(input);

        // Input validation
        if (number < 1 || number > 30) {
            printf("Please enter a valid number between 1 and 30.\n");
        } else {
            break; // valid input, exit loop
        }
    }

    // Measure time taken
    clock_t start_time = clock();
    
    printf("\nFibonacci sequence up to %d terms:\n", number);
    printFibonacci(number);

    // Measure end time and calculate duration
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTime taken to generate the Fibonacci sequence: %f seconds\n", time_taken);

    return 0;
}

// Recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1) {
        return n; // base cases: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive case
}

// Function to print the Fibonacci sequence
void printFibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i)); // Call the recursive function
    }
    printf("\n"); // New line after printing the sequence
}