//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

// Function to print Fibonacci sequence up to n terms using recursion
void printFibonacci(int n, int a, int b) {
    // Base case: if n becomes zero, return
    if (n == 0) {
        return;
    }

    // Print the current Fibonacci number
    printf("%d ", a);

    // Recursive call with the next two Fibonacci numbers
    printFibonacci(n - 1, b, a + b);
}

// Function to generate a pattern for fun
void printPattern(int n) {
    printf("Generating a fun pattern based on Fibonacci:\n");
    for (int i = 1; i <= n; i++) {
        // Print a few spaces for alignment
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // Print asterisks corresponding to the Fibonacci number at position i
        printf("*");
        for (int j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main function to drive the program
int main() {
    int num;

    printf("Welcome to the Fibonacci generator!\n");
    printf("How many terms of the Fibonacci sequence would you like to see? ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci sequence:\n");
    // Start generating the Fibonacci sequence from the first two numbers
    printFibonacci(num, 0, 1);
    printf("\n");

    // Call the pattern printing function
    printPattern(num);

    return 0;
}