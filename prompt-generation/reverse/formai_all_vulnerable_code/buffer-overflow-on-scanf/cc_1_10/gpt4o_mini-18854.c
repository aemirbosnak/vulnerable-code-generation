//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TERMS 25
#define DELAY 500000 // Delay in microseconds

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void printFibonacci(int terms) {
    int fib[MAX_TERMS];
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number

    // Generate Fibonacci sequence
    for (int i = 2; i < terms; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Shockingly visualize the sequence
    for (int i = 0; i < terms; i++) {
        
        // RAINBOW FIBONACCI DISPLAY
        switch (i % 7) {
            case 0: printf("\033[0;31m"); break; // Red
            case 1: printf("\033[0;33m"); break; // Yellow
            case 2: printf("\033[0;32m"); break; // Green
            case 3: printf("\033[0;36m"); break; // Cyan
            case 4: printf("\033[0;34m"); break; // Blue
            case 5: printf("\033[0;35m"); break; // Magenta
            case 6: printf("\033[0;37m"); break; // White
        }

        printf("F(%d) = %d\n", i, fib[i]);
        usleep(DELAY); // Add shock factor with delay
    }
    // Reset color
    printf("\033[0m");
}

int main() {
    int terms;
    
    clearScreen();
    printf("Welcome to the SHOCKING Fibonacci Sequence Visualizer!\n");
    printf("How many terms do you want to see (max %d)? ", MAX_TERMS);
    
    // Get the number of terms from user
    scanf("%d", &terms);
    
    // Validate input
    if (terms < 1 || terms > MAX_TERMS) {
        printf("Please enter a number between 1 and %d!\n", MAX_TERMS);
        return 1;
    }

    // Start displaying the Fibonacci sequence
    printFibonacci(terms);
    
    // Final message
    printf("\n\nSHOCKING DISPLAY COMPLETE! Bye!\n");
    return 0;
}