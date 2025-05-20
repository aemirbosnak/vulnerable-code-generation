//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FIB_INDEX 50

// Function Prototypes
void printMenu();
int getInput();
void calculateFibonacci(int n, unsigned long long *fibArray);
void visualizeFibonacci(unsigned long long *fibArray, int n);
void displayFibonacciNumber(unsigned long long num);

int main() {
    int n;  
    unsigned long long fibArray[MAX_FIB_INDEX];

    printMenu();
    n = getInput();

    if (n < 0 || n >= MAX_FIB_INDEX) {
        printf("Error: Please enter a number between 0 and %d.\n", MAX_FIB_INDEX - 1);
        return EXIT_FAILURE;
    }

    calculateFibonacci(n, fibArray);
    visualizeFibonacci(fibArray, n);

    return EXIT_SUCCESS;
}

void printMenu() {
    printf("===================================\n");
    printf("       Fibonacci Visualizer       \n");
    printf("===================================\n");
    printf("Enter a number of Fibonacci terms to visualize (0 - %d): ", MAX_FIB_INDEX - 1);
}

int getInput() {
    int input;
    printf("> ");
    while (scanf("%d", &input) != 1) {
        printf("Invalid input. Please enter a number: ");
        while (getchar() != '\n'); // clear invalid input
    }
    return input;
}

void calculateFibonacci(int n, unsigned long long *fibArray) {
    if (n >= 1) {
        fibArray[0] = 0; // F(0)
    }
    if (n >= 2) {
        fibArray[1] = 1; // F(1)
    }
    // Calculate Fibonacci numbers iteratively
    for (int i = 2; i < n; i++) {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
}

void visualizeFibonacci(unsigned long long *fibArray, int n) {
    printf("\nFibonacci Sequence (first %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        displayFibonacciNumber(fibArray[i]);
    }
    printf("\n");
}

void displayFibonacciNumber(unsigned long long num) {
    printf("%llu ", num);
    // Visual representation - asterisks
    for (unsigned long long i = 0; i < num; i += 1000) {
        printf("*");
    }
    printf("\n");
}