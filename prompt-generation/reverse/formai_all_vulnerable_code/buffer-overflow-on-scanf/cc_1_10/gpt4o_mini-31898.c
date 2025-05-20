//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 50
#define DELAY 100000 // delay in microseconds

void clearScreen() {
    printf("\033[H\033[J");
}

void printFibonacci(int n) {
    long long fib[MAX_TERMS];
    int i;

    // Initializing the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;
    
    // Generating the Fibonacci series
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Visualizing the Fibonacci sequence in a colorful manner
    for (i = 0; i < n; i++) {
        printf("\033[1;34mFibonacci Term %2d: ", i);
        printf("\033[1;32m%lld\033[0m\n", fib[i]);
        usleep(DELAY);
    }
}

void lineGraph(int n, long long *fib) {
    printf("\n\033[1;35mFibonacci Sequence Graph:\033[0m\n");
    for (int i = 0; i < n; i++) {
        printf("\033[1;33mTerm %2d:\033[0m ", i);
        for (long long j = 0; j < fib[i] / 100; j++) { // Scale for graphing
            printf("█");
        }
        printf(" \033[1;32m%lld\033[0m\n", fib[i]);
    }
}

int main() {
    int n;

    // Introduction
    clearScreen();
    printf("\033[1;36mWelcome to the Fibonacci Sequence Visualizer!\033[0m\n");
    printf("How many terms of the Fibonacci sequence would you like to generate? (max %d): ", MAX_TERMS);
    
    // Input validation for number of terms
    while (1) {
        if (scanf("%d", &n) != 1 || n < 1 || n > MAX_TERMS) {
            printf("Invalid input! Please enter a number between 1 and %d: ", MAX_TERMS);
            while(getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }
    
    long long fib[MAX_TERMS];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printFibonacci(n);
    lineGraph(n, fib);

    printf("\n\033[1;36mThank you for using the Fibonacci Sequence Visualizer!\033[0m\n");
    return 0;
}