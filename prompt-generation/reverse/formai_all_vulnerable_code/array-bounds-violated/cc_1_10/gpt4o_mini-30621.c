//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n);
void drawBar(int length);

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many Fibonacci numbers would you like to visualize? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
    } else {
        printFibonacci(n);
    }
    
    return 0;
}

// Function to print Fibonacci numbers and their respective bars
void printFibonacci(int n) {
    long long fib[n]; // Using long long to accommodate larger Fibonacci values
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number

    printf("Fibonacci Sequence:\n");
    printf("%-10s %-10s\n", "Index", "Value");
    printf("----------------------\n");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fib[i] = 0;
        } else if (i == 1) {
            fib[i] = 1;
        } else {
            fib[i] = fib[i - 1] + fib[i - 2]; // Calculate Fibonacci
        }
        
        printf("%-10d %-10lld ", i, fib[i]);
        drawBar(fib[i]); // Draw the bar corresponding to the Fibonacci number
        printf("\n");
    }
}

// Function to draw a bar representing the Fibonacci number
void drawBar(int length) {
    int scaledLength = length / 100; // Scale down for better visualization
    if (scaledLength == 0 && length != 0) {
        scaledLength = 1; // Minimum bar length
    }

    for (int j = 0; j < scaledLength; j++) {
        printf("*"); // Print bar using asterisks
    }
}