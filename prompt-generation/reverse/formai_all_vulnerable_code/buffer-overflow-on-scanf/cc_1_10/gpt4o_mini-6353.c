//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 20

// Function prototypes
void generateFibonacci(int *fibonacciArray, int terms);
void printFibonacciSequence(int *fibonacciArray, int terms);
void visualizeFibonacci(int *fibonacciArray, int terms);

int main() {
    int fibonacciArray[MAX_TERMS];
    
    int numTerms;
    
    printf("Enter the number of Fibonacci terms to generate (max %d): ", MAX_TERMS);
    scanf("%d", &numTerms);

    if (numTerms > MAX_TERMS || numTerms <= 0) {
        printf("Please enter a valid number of terms (1 to %d).\n", MAX_TERMS);
        return 1; // Exit with error if input is invalid
    }

    generateFibonacci(fibonacciArray, numTerms);
    printf("\nFibonacci Sequence:\n");
    printFibonacciSequence(fibonacciArray, numTerms);
    printf("\nVisual Representation:\n");
    visualizeFibonacci(fibonacciArray, numTerms);

    return 0;
}

// Function to generate Fibonacci sequence
void generateFibonacci(int *fibonacciArray, int terms) {
    if (terms >= 1) fibonacciArray[0] = 0;
    if (terms >= 2) fibonacciArray[1] = 1;
    for (int i = 2; i < terms; i++) {
        fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
    }
}

// Function to print Fibonacci sequence
void printFibonacciSequence(int *fibonacciArray, int terms) {
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacciArray[i]);
    }
    printf("\n");
}

// Function to visualize Fibonacci sequence with asterisks
void visualizeFibonacci(int *fibonacciArray, int terms) {
    for (int i = 0; i < terms; i++) {
        printf("%2d: ", fibonacciArray[i]); // Print the Fibonacci number
        for (int j = 0; j < fibonacciArray[i]; j+=1000) { // Adjust the dividen for larger outputs with array
            printf("*");
        }
        printf("\n");
    }
}