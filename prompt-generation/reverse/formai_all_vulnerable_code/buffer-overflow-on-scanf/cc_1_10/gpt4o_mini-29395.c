//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() {
    // Clear the terminal screen using ANSI escape codes
    printf("\033[H\033[J");
}

void printFibonacci(int terms) {
    // Variables to hold the Fibonacci numbers
    long long int fib1 = 0, fib2 = 1, nextTerm;
    printf("Fibonacci Sequence: \n");
    printf("%lld\n", fib1);
    printf("%lld\n", fib2);
    
    for(int i = 3; i <= terms; i++) {
        // Calculate the next term
        nextTerm = fib1 + fib2;
        printf("%lld\n", nextTerm);
        
        // Update the previous two terms
        fib1 = fib2;
        fib2 = nextTerm;
    }
}

void visualizeFibonacci(int terms) {
    // Visual representation of the Fibonacci sequence
    long long int fib1 = 0, fib2 = 1, nextTerm;

    clearScreen();
    printf("Visualizing Fibonacci Sequence:\n");

    // Print the graphical representation
    for (int i = 0; i < terms; i++) {
        if (i == 0) {
            printf("%2d: %llu\n", i, fib1);
        } else if (i == 1) {
            printf("%2d: %llu\n", i, fib2);
            printf("\n");
        } else {
            nextTerm = fib1 + fib2;
            printf("%2d: %llu\n", i, nextTerm);
            fib1 = fib2;
            fib2 = nextTerm;
            printf("\n");
        }

        int length = i == 0 ? 1 : i == 1 ? 1 : nextTerm % 50; // Mod to limit size
        for (int j = 0; j < length; j++) {
            printf("█");
        }
        printf("\n");
    }
}

int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to visualize (up to 30): ");
    scanf("%d", &terms);

    if (terms > 30 || terms < 1) {
        printf("Please enter a valid number of terms between 1 and 30.\n");
        return 1;
    }

    printFibonacci(terms);
    printf("\n");
    sleep(1); // Pause after displaying sequence
    visualizeFibonacci(terms);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}