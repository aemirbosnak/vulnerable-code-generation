//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 50

void printFibonacci(int terms);
void visualizeFibonacci(int *fibonacci, int terms);
void paranoidDelay(int seconds);

int main() {
    int fibonacci[MAX_TERMS];
    int numTerms;

    printf("Welcome to the Fibonacci Sequence Visualizer...\n");
    paranoidDelay(2);

    printf("Please enter the number of terms you want to visualize (up to %d): ", MAX_TERMS);
    scanf("%d", &numTerms);

    if(numTerms < 1 || numTerms > MAX_TERMS) {
        printf("Invalid number of terms! Please input a number between 1 and %d.\n", MAX_TERMS);
        return EXIT_FAILURE;
    }

    printf("\nGenerating Fibonacci sequence...\n");
    paranoidDelay(2);
    
    // Populate Fibonacci sequence
    fibonacci[0] = 0;
    if(numTerms > 1) {
        fibonacci[1] = 1;
    }

    for(int i = 2; i < numTerms; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    printf("\nThe Fibonacci sequence is:\n");
    printFibonacci(numTerms);
    
    printf("\nVisualizing the Fibonacci sequence...\n");
    paranoidDelay(2);
    visualizeFibonacci(fibonacci, numTerms);

    return EXIT_SUCCESS;
}

void printFibonacci(int terms) {
    // Print each Fibonacci term
    for(int i = 0; i < terms; i++) {
        printf("%d ", (i < 2) ? i : i - 1 + i - 2);
    }
    printf("\n");
}

void visualizeFibonacci(int *fibonacci, int terms) {
    for(int i = 0; i < terms; i++) {
        // Draw the Fibonacci term as asterisks (visualization)
        for(int j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", fibonacci[i]);
    
        // Sleep to visualize one term at a time
        paranoidDelay(1);
    }
}

void paranoidDelay(int seconds) {
    // A small delay to avoid suspicion
    printf("Delaying for %d seconds... Please wait...\n", seconds);
    for(int i = seconds; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
}