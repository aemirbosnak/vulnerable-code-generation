//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <string.h>

void printFibonacci(int n) {
    long long a = 0, b = 1, c;

    printf("Fibonacci Sequence:\n");
    printf("-------------------\n");
    printf("1: %lld\n", a);
    printf("2: %lld\n", b);
    
    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d: %lld\n", i, c);
        a = b;
        b = c;
        usleep(500000); // Sleep for 500 milliseconds for visual effect
    }
}

void visualizeFibonacci(int n) {
    long long a = 0, b = 1, c;
    
    // Create a visual representation with dynamic adjustments
    printf("\nVisualizing Fibonacci Sequence up to %d terms:\n", n);
    printf("------------------------------------------------\n");

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%3d: ", i);
            printf("*%*s\n", (int)a, "");
            continue;
        } 
        if (i == 2) {
            printf("%3d: ", i);
            printf("*%*s\n", (int)b, "");
            continue;
        }

        // Calculate the next Fibonacci number
        c = a + b;
        a = b;
        b = c;

        // Visualize it
        printf("%3d: ", i);
        for (int j = 0; j < c; j+=100000) { // Adjust scaling
            printf("*");
        }
        printf(" (%lld)\n", c);
        usleep(500000); // Sleep for 500 milliseconds for visual effect
    }
}

int main() {
    int n;

    // Clear the screen
    printf("\033[H\033[J");
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    
    // Get user input
    printf("Enter the number of terms to visualize: ");
    scanf("%d", &n);

    // Input validation
    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    // Print and visualize the Fibonacci sequence
    printFibonacci(n);
    visualizeFibonacci(n);

    printf("------------------------------------------------\n");
    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");

    return 0;
}