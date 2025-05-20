//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to calculate Fibonacci numbers
unsigned long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to visualize Fibonacci sequence
void visualizeFibonacci(int terms) {
    printf("\nFibonacci Sequence:\n");
    for (int i = 0; i < terms; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n\n");
}

// Function to visualize values in a graphical format
void graphicalFibonacci(int terms) {
    printf("Graphical Representation of Fibonacci Sequence:\n");
    for (int i = 0; i < terms; i++) {
        unsigned long long fibNumber = fibonacci(i);
        printf("%2d: ", i); // Print the index
        for (unsigned long long j = 0; j < fibNumber; j += 100000) { // Increment by 100,000 for visibility
            printf("#");
        }
        printf(" (%llu)\n", fibNumber); // Print the Fibonacci number
    }
    printf("\n");
}

// Function to create a simple text file for storing Fibonacci sequence
void saveFibonacciToFile(int terms) {
    FILE *file = fopen("fibonacci_sequence.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < terms; i++) {
        fprintf(file, "%llu\n", fibonacci(i));
    }

    fclose(file);
    printf("Fibonacci sequence saved to 'fibonacci_sequence.txt'\n");
}

int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you wish to visualize: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    // Visualize the Fibonacci sequence
    visualizeFibonacci(terms);

    // Provide graphical representation
    graphicalFibonacci(terms);

    // Save to file
    saveFibonacciToFile(terms);

    return 0;
}