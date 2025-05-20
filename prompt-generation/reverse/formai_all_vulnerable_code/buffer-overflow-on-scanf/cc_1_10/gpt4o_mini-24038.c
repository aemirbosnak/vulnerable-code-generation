//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n);
void printSpaces(int count);
void printFibonacciNumber(int num, int index);
void visualizeFibonacci(int num);

int main() {
    int count;

    printf("Enter the number of Fibonacci numbers to visualize: ");
    if (scanf("%d", &count) != 1 || count < 1) {
        fprintf(stderr, "Invalid input! Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    printFibonacci(count);
    return EXIT_SUCCESS;
}

void printFibonacci(int n) {
    int fib1 = 0, fib2 = 1, temp;

    printf("Fibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        int currentFib = (i <= 1) ? i : fib1 + fib2;
        visualizeFibonacci(currentFib);
        
        // Prepare the next Fibonacci number
        fib1 = fib2;
        fib2 = currentFib;
    }
}

void visualizeFibonacci(int num) {
    printf("%d: ", num);
    printFibonacciNumber(num, 0);
    printf("\n");
}

void printFibonacciNumber(int num, int index) {
    // This function prints a visual representation of the Fibonacci number using asterisks
    if (num <= 0) {
        printSpaces(index);
        printf("|\n");
        return;
    }

    // Recursive call to print the current Fibonacci number visually
    printSpaces(index);
    for (int i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");

    // Visualize children Fibonacci numbers
    printFibonacciNumber(num - 1, index + 1);
    printFibonacciNumber(num - 2, index + 1);
}

void printSpaces(int count) {
    // This function prints spaces for indentation
    for (int i = 0; i < count; i++) {
        printf("   ");
    }
}