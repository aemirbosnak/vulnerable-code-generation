//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() {
    // System call to clear the terminal screen
    printf("\033[H\033[J");
}

void printFibonacci(int n) {
    int a = 0, b = 1, c;
    int i = 0;

    // Print the Fibonacci sequence up to the nth term
    printf("Fibonacci Sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

void visualizeFibonacci(int n) {
    int a = 0, b = 1, c;
    int i;
    
    clearScreen();
    printf("Visualizing Fibonacci Sequence:\n\n");

    // Visualizing with asterisks
    for (i = 0; i < n; i++) {
        printf("Fibonacci(%d): ", i);
        printf(" ");
        for (int j = 0; j < a; j++) {
            printf("*");
        }
        printf("\n");
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;

    // Introduction
    printf("===================================\n");
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("===================================\n");
    
    // User input for the length of Fibonacci sequence
    printf("Enter the number of terms in Fibonacci sequence you want to visualize: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Initial call to print the sequence
    printFibonacci(n);

    // Pause before visualization
    printf("\nPress Enter to see the visualization...");
    while (getchar() != '\n'); // Clear newline character
    getchar(); // Wait for user to press Enter

    // Call to visualize Fibonacci
    visualizeFibonacci(n);

    // Concluding message
    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    printf("===================================\n");

    return 0;
}