//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to clear the console
void clearConsole() {
    printf("\033[H\033[J"); // ANSI escape code to clear the console
}

// Function to print warning messages
void printWarning(const char *message) {
    printf("\033[1;31mWARNING: %s\033[0m\n", message); // Red colored warning
}

// Function to pause execution
void pauseExecution(int seconds) {
    printf("PAUSING FOR %d SECONDS. STAY ALERT!\n", seconds);
    sleep(seconds);
}

// Function to generate Fibonacci numbers
void generateFibonacci(int count) {
    long long fib1 = 0, fib2 = 1, next;

    printf("GENERATING FIBONACCI NUMBERS. STAY VIGILANT...\n");
    for (int i = 0; i < count; i++) {
        if (i == 0) {
            printf("%lld\n", fib1);
            continue;
        }
        if (i == 1) {
            printf("%lld\n", fib2);
            continue;
        }
        next = fib1 + fib2;
        printf("%lld\n", next);
        fib1 = fib2;
        fib2 = next;

        if (i % 5 == 0) {
            printWarning("Generating large numbers! Keep your eyes peeled!");
            pauseExecution(2);
        }
    }
}

// Function to visualize Fibonacci sequence
void visualizeFibonacci(int count) {
    long long fib1 = 0, fib2 = 1, next;

    clearConsole();

    printf("VISUALIZING FIBONACCI SEQUENCE. PROCEED WITH CAUTION...\n");

    for (int i = 0; i < count; i++) {
        if (i == 0) {
            printf("F(0): ");
            for (int j = 0; j < fib1; j++) printf("*");
            printf(" (%lld)\n", fib1);
            continue;
        }
        if (i == 1) {
            printf("F(1): ");
            for (int j = 0; j < fib2; j++) printf("*");
            printf(" (%lld)\n", fib2);
            continue;
        }
        next = fib1 + fib2;

        printf("F(%d): ", i);
        for (int j = 0; j < next; j++) printf("*");
        printf(" (%lld)\n", next);

        fib1 = fib2;
        fib2 = next;

        if (i % 5 == 0 && i != 0) {
            printWarning("Too many stars! Is someone watching us?");
            pauseExecution(2);
        }
    }

    printf("\nDONE VISUALIZING. BUT STAY ALERT FOR ANOMALIES!\n");
}

// Main function
int main() {
    int count;

    printf("WELCOME TO THE FIBONACCI VISUALIZER!\n");
    pauseExecution(1);
    
    printf("WARNING: Make sure you are in a secure environment.\n");
    pauseExecution(2);
    
    printf("Please enter the number of Fibonacci numbers to generate (1-50): ");
    scanf("%d", &count);

    if (count < 1 || count > 50) {
        printWarning("Invalid input! Make sure to enter a number between 1 and 50!");
        return 1;
    }

    generateFibonacci(count);
    pauseExecution(2);
    visualizeFibonacci(count);

    printf("END OF PROGRAM. KEEP ALL SENSITIVE INFORMATION SECURE.\n");
    return 0;
}