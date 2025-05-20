//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printColored(char *text, const char *colorCode) {
    printf("%s%s\033[0m", colorCode, text);
}

void printFibonacci(int n) {
    long long first = 0, second = 1, next;
    char colorCode[10];

    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i; // First two Fibonacci numbers are 0 and 1
        else {
            next = first + second; // Fibonacci equation
            first = second; // Move forward
            second = next; 
        }

        // Generate a random color code for visual surprise
        sprintf(colorCode, "\033[3%dm", rand() % 8); // Random text color

        // Print the Fibonacci number
        printColored("Fibonacci(", "\033[1;34m");
        printf("%d", i);
        printColored("): ", "\033[1;34m");
        printf("%lld ", next);

        // Visualize the number with asterisks
        for (long long j = 0; j < next; j++) {
            // Change color for each asterisk to add more visual surprise
            sprintf(colorCode, "\033[3%dm", rand() % 8);
            printColored("*", colorCode);
            usleep(50000); // Sleep for a short while for effect
        }
        
        printf("\n"); // New line after each Fibonacci number
    }
}

int main() {
    int n;

    printColored("Welcome to the Fibonacci Sequence Visualizer!\n", "\033[1;32m");
    
    printf("How many Fibonacci numbers would you like to see? ");
    scanf("%d", &n);

    if (n < 0) {
        printColored("Please enter a non-negative integer.\n", "\033[1;31m");
        return 1;
    }

    printColored("Here we go! Visualizing...\n", "\033[1;35m");
    
    printFibonacci(n);

    printColored("\nThank you for using the Fibonacci Sequence Visualizer!\n", "\033[1;32m");
    return 0;
}