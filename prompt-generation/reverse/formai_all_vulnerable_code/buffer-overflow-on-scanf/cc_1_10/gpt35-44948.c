//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>

// Function to generate Fibonacci sequence up to given input terms
void generateFibonacciSequence(int termCount) {
    int num1 = 0, num2 = 1, nextNum, i;

    // Print first two terms
    printf("%d, %d, ", num1, num2);

    for (i = 2; i < termCount; i++) {
        nextNum = num1 + num2;
        printf("%d, ", nextNum);
        num1 = num2;
        num2 = nextNum;
    }
    printf("\n");
}

// Function to generate graphic visual of the Fibonacci sequence
void generateFibonacciSequenceVisual(int termCount) {
    int num1 = 0, num2 = 1, nextNum, i, j, repeat;
    repeat = termCount / 10;

    // Print first two terms
    printf("%d\n%d\n", num1, num2);
    
    // Loop for remaining terms to create visual
    for (i = 2; i < termCount; i++) {
        nextNum = num1 + num2;
        num1 = num2;
        num2 = nextNum;

        // Print each number with asterisks representing its value
        printf("%d ", nextNum);
        for (j = 0; j < nextNum*repeat; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int terms;
    printf("Enter number of Fibonacci terms to generate: ");
    scanf("%d", &terms);

    // Generate and print Fibonacci sequence
    printf("\nFibonacci sequence up to %d terms:\n", terms);
    generateFibonacciSequence(terms);

    // Generate and print visual of Fibonacci sequence
    printf("\nFibonacci sequence visual up to %d terms:\n", terms);
    generateFibonacciSequenceVisual(terms);

    return 0;
}